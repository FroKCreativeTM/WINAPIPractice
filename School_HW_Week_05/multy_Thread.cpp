/*
작성자 : 차승철
학번 : 180502
작성일 : 20.04.19
제목 : multi_thread.cpp
설명 : 스레드 4개의 멀티 스레드 환경을 만들고 이를 이용해서 싱글 스레드 환경에 비해서 얼마나 빨라졌나
그리고 얼마나 정밀한가를 체크하기 위한 프로그램입니다..
*/

#include <Windows.h>
#include <iostream>
#include <ctime>

/* 다트 수 */
unsigned int DARTS_SIZE = 40000000;

/* 4개의 스레드 */
const unsigned int MAX_THREAD_SIZE = 4;
HANDLE g_arrThread[MAX_THREAD_SIZE];

/* WINAPI runtime stack */
DWORD WINAPI MyFunction(LPVOID param)
{
	int in_circle = 0;

	for (size_t i = 0; i < DARTS_SIZE / 4; i++)
	{
		// 모든 x와 y는 1 안에 있다.
		// 이는 x, y축으로는 -1과 1 사이에 있다는 뜻
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;

		// 원의 방정식을 이용해서 이 수가 원의 안에 있는가를 확인한다.
		// 이 때 원의 반지름은 1이다.
		if ((x * x) + (y * y) <= 1)
		{
			in_circle++;
		}
	}

	*(int*)param = in_circle;

	return 0;
}

int main(int argc, char ** argv)
{
	srand((unsigned int)time(NULL));

	DWORD thread_id[MAX_THREAD_SIZE];
	int in_circle[4] = { 0,0,0,0 };		// 데드락 현상 방지를 위해서 전역변수 사용 금지!
	int totalInCircle = 0;
	clock_t startTime, endTime;

	startTime = clock();

	// 총 스레드가 4개
	for (size_t i = 0; i < 4; i++)
	{
		// 각각 천만개씩 주겠습니다.
		unsigned int idxCount = DARTS_SIZE / 4;

		g_arrThread[i] = CreateThread
		(
			NULL,				/* default secutiry attributes */
			0,					/* default stack size */
			MyFunction,			/* thread function */
			&in_circle[i],		/* parameter of thread function */
			0,					/* default creation flags */
			&thread_id[i]		/* returns the thread identifier */
		);
	}

	/* now wait for the threads to finish */
	WaitForMultipleObjects(MAX_THREAD_SIZE, g_arrThread, true, INFINITE);

	/* close the threads handle */
	for (size_t i = 0; i < MAX_THREAD_SIZE; i++)
	{
		if(g_arrThread != NULL)
			CloseHandle(g_arrThread[i]);
	}

	for (size_t i = 0; i < MAX_THREAD_SIZE; i++)
	{
		totalInCircle += in_circle[i];
	}

	// 각 스레드가 구한 원 안의 값과 총 다트 던진 수를 나눈 뒤 이 값에 4를 곱하면
	// PI값이 나옵니다.
	printf("<Multi-Thread>\n");
	printf("PI = %0.7lf\n", ((double)totalInCircle / (double)DARTS_SIZE) * 4);

	endTime = clock();
	printf("Time : %lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

	return 0;
}