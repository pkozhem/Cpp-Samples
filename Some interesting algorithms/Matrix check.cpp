#include <iostream>
using namespace std;

int main()
{
	int M, N;
	int pMin, pMax, *buffer;
	printf("enter matrix size: \n");
	cin >> M >> N;
	int** matrix = new int* [M];
	for (int i = 0; i < M; i++)
	{
		matrix[i] = new int[N];
	}

	printf("input matrix \n");

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "[" << i << "][" << j << "]";
			cin >> matrix[i][j];
		}
	}

	printf("your matrix: \n");

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j];
		}
		printf("\n");
	}

	int minVal = matrix[0][0];
	int maxVal = matrix[M - 1][N - 1];
	pMin = 0;
	pMax = N - 1;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (minVal > matrix[i][j])
			{
				minVal = matrix[i][j];
				pMin = i;
			}
		}
	}

	

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maxVal < matrix[i][j])
			{
				maxVal = matrix[i][j];
				pMax = i;
			}
		}
	}

	cout << endl << pMin << endl << pMax << endl;
	
	buffer = matrix[pMin];
	matrix[pMin] = matrix[pMax];
	matrix[pMax] = buffer;
	cout << endl << endl;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j];
		}
		printf("\n");
	}

	delete[] matrix;
	return 0;
}
