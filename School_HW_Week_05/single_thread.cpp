/*
작성자 : 차승철
학번 : 180502
작성일 : 20.04.19
제목 : single_thread.cpp
설명 : 단순히 주 스레드를 이용해서 구해본 PI값으로 얼마나 정밀한가는 생각하지 않고 단순히 
싱글 스레드 상에서 얼마나 걸리는가를 체크하기 위한 프로그램입니다.
*/

#include <Windows.h>
#include <iostream>
#include <ctime>

// 전역 변수
DWORD g_in_circle = 0;	// 원 안에 들어가는 다트 수

/* 단순 주 스레드만을 이용한 파이 계산 */
int main()
{
	srand((unsigned int)time(NULL));

	clock_t startTime, endTime;
	int idxLength = 40000000;

	startTime = clock();

	for (size_t i = 0; i < idxLength; i++)
	{
		// 모든 x와 y는 1 안에 있다.
		// 이는 x, y축으로는 -1과 1 사이에 있다는 뜻
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;

		// 원의 방정식을 이용해서 이 수가 원의 안에 있는가를 확인한다.
		// 이 때 원의 반지름은 1이다.
		if ((x * x) + (y * y) <= 1)
		{
			g_in_circle++;
		}
	}

	// 단순히 메인 함수 안에서 구한 원 안의 값과 총 다트 던진 수를 나눈 뒤 이 값에 4를 곱하면
	// 파이 값이 나옵니다.
	printf("<Single-Thread>\n");
	printf("PI = %0.7lf\n", ((double)g_in_circle / (double)idxLength) * 4);

	endTime = clock();
	printf("Time : %lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

	return 0;
}