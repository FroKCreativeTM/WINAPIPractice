#include <iostream>
#include <Windows.h>
#include <ctime>

DWORD Sum;

DWORD WINAPI TestFunction(LPVOID lpThreadParameter)
{
	DWORD upper = *(DWORD*)lpThreadParameter;
	for (DWORD i = 0; i <= upper; i++)
	{
		Sum += i;
	}
	return 0;
}

int main(int argc, char ** argv)
{
	HANDLE hThread;
	DWORD thread_id;
	int param;
	clock_t startTime, endTime;

	startTime = clock();

	if (argc != 2)
	{
		fprintf(stderr, "An integer parameter is required\n");
		return -1;
	}
	param = atoi(argv[1]);
	if (param < 0)
	{
		fprintf(stderr, "An integer >= 0 is required\n");
		return -1;
	}

	hThread = CreateThread(
		NULL,
		0,
		TestFunction,
		&param,
		0,
		&thread_id
	);

	if (hThread != NULL)
	{
		/* now wait for the thread to finish */
		WaitForSingleObject(hThread, INFINITE);

		/* close the thread handle */
		CloseHandle(hThread);

		printf("sum = %d\n", Sum);
	}

	endTime = clock();
	printf("Time : %lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
	   	  
	return 0;
}