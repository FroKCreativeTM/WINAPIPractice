#include <Windows.h>
#include <iostream>
#include <ctime>

typedef long long LONGLONG;

/* ������ �����ڿ� */
DWORD sum;

/* ��Ʈ �� */
const LONGLONG DARTS_SIZE = 40000000;

/* 4���� ������ */
const unsigned int MAX_THREAD_SIZE = 4;
HANDLE arrThread[MAX_THREAD_SIZE];

/* WINAPI runtime stack */
DWORD WINAPI MyFunction(LPVOID param)
{
	int in_circle;

	return 0;
}

int main(int argc, char ** argv)
{
	DWORD thread_id;
	int round = 2;
	int in_circle[MAX_THREAD_SIZE] = { 0,0,0,0 };

	clock_t startClock, endClock;

	srand((unsigned int)time(nullptr));



	for (size_t i = 0; i < 4; i++)
	{
		arrThread[i] = CreateThread
		(
			NULL,				/* default secutiry attributes */
			0,					/* default stack size */
			MyFunction,			/* thread function */
			&in_circle[i],		/* parameter of thread function */
			0,					/* default creation flags */
			&thread_id			/* returns the thread identifier */
		);
	}

	

	return 0;
}