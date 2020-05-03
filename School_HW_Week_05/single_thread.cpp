/*
�ۼ��� : ����ö
�й� : 180502
�ۼ��� : 20.04.19
���� : single_thread.cpp
���� : �ܼ��� �� �����带 �̿��ؼ� ���غ� PI������ �󸶳� �����Ѱ��� �������� �ʰ� �ܼ��� 
�̱� ������ �󿡼� �󸶳� �ɸ��°��� üũ�ϱ� ���� ���α׷��Դϴ�.
*/

#include <Windows.h>
#include <iostream>
#include <ctime>

// ���� ����
DWORD g_in_circle = 0;	// �� �ȿ� ���� ��Ʈ ��

/* �ܼ� �� �����常�� �̿��� ���� ��� */
int main()
{
	srand((unsigned int)time(NULL));

	clock_t startTime, endTime;
	int idxLength = 40000000;

	startTime = clock();

	for (size_t i = 0; i < idxLength; i++)
	{
		// ��� x�� y�� 1 �ȿ� �ִ�.
		// �̴� x, y�����δ� -1�� 1 ���̿� �ִٴ� ��
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;

		// ���� �������� �̿��ؼ� �� ���� ���� �ȿ� �ִ°��� Ȯ���Ѵ�.
		// �� �� ���� �������� 1�̴�.
		if ((x * x) + (y * y) <= 1)
		{
			g_in_circle++;
		}
	}

	// �ܼ��� ���� �Լ� �ȿ��� ���� �� ���� ���� �� ��Ʈ ���� ���� ���� �� �� ���� 4�� ���ϸ�
	// ���� ���� ���ɴϴ�.
	printf("<Single-Thread>\n");
	printf("PI = %0.7lf\n", ((double)g_in_circle / (double)idxLength) * 4);

	endTime = clock();
	printf("Time : %lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

	return 0;
}