/*
�ۼ��� : ����ö
�й� : 180502
�ۼ��� : 20.04.19
���� : multi_thread.cpp
���� : ������ 4���� ��Ƽ ������ ȯ���� ����� �̸� �̿��ؼ� �̱� ������ ȯ�濡 ���ؼ� �󸶳� ��������
�׸��� �󸶳� �����Ѱ��� üũ�ϱ� ���� ���α׷��Դϴ�..
*/

#include <Windows.h>
#include <iostream>
#include <ctime>

/* ��Ʈ �� */
unsigned int DARTS_SIZE = 40000000;

/* 4���� ������ */
const unsigned int MAX_THREAD_SIZE = 4;
HANDLE g_arrThread[MAX_THREAD_SIZE];

/* WINAPI runtime stack */
DWORD WINAPI MyFunction(LPVOID param)
{
	int in_circle = 0;

	for (size_t i = 0; i < DARTS_SIZE / 4; i++)
	{
		// ��� x�� y�� 1 �ȿ� �ִ�.
		// �̴� x, y�����δ� -1�� 1 ���̿� �ִٴ� ��
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;

		// ���� �������� �̿��ؼ� �� ���� ���� �ȿ� �ִ°��� Ȯ���Ѵ�.
		// �� �� ���� �������� 1�̴�.
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
	int in_circle[4] = { 0,0,0,0 };		// ����� ���� ������ ���ؼ� �������� ��� ����!
	int totalInCircle = 0;
	clock_t startTime, endTime;

	startTime = clock();

	// �� �����尡 4��
	for (size_t i = 0; i < 4; i++)
	{
		// ���� õ������ �ְڽ��ϴ�.
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

	// �� �����尡 ���� �� ���� ���� �� ��Ʈ ���� ���� ���� �� �� ���� 4�� ���ϸ�
	// PI���� ���ɴϴ�.
	printf("<Multi-Thread>\n");
	printf("PI = %0.7lf\n", ((double)totalInCircle / (double)DARTS_SIZE) * 4);

	endTime = clock();
	printf("Time : %lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

	return 0;
}