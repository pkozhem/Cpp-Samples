#include <iostream>
using namespace std;

int main()
{
	int M, N;
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


	printf("min value above side diagonal: \n");
	int minVal = matrix[0][0];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			if (minVal > matrix[i][j])
			{
				minVal = matrix[i][j];
			}
		}
	}
	cout << minVal << endl;


	printf("max value under main diagonal: \n");
	int maxVal = matrix[0][N - 1];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 0 + i; j++)
		{
			if (maxVal < matrix[i][j])
			{
				maxVal = matrix[i][j];
			}
		}
	}
	cout << maxVal << endl;

	delete[] matrix;
	return 0;
}