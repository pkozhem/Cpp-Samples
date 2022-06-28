/*Some simple functions with two dimensional arrays*/
#include <iostream>
#include <cmath>
using namespace std;

void fillMatrix(double** matrix, double* arr, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout << "enter [" << i << "][" << j << "] coefficient: ";
			cin >> matrix[i][j];
		}
		cout << "enter[" << i << "]free coefficient: ";
		cin >> arr[i];
		cout << endl;
	}
}

void viewEqualations(double** matrix, double* arr, int size)
{
	int i, j, k;
	cout << "your system of equalations: " << endl;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout << " + " << matrix[i][j] << "x[" << j + 1 << "]";
		}
		cout << " = " << arr[i] << endl;
	}
}

void conversionMatrix(double** matrix, double* arr, int size)
{
	int i, j, k, c,max=0;
	for (j = 0; j < size; j++)
	{
		max = j;
		for (int g = j; g < size; g++)
		{
			if (fabs(matrix[g][j]) > fabs(matrix[max][j])) max = g;
		}
		swap(matrix[max], matrix[j]);
		swap(arr[max], arr[j]);
		for (i = j + 1; i < size; i++)
		{
			c = matrix[i][j] / matrix[j][j];
			for (k = j; k < size; k++)
			{
				matrix[i][k] = matrix[i][k] - matrix[j][k] * c;
			}
			arr[i] = arr[i] - arr[j] * c;
		}
	}
}

void solveEquations(double** matrix, double* arr, double* x, int size)
{
	int i, j;
	x[size - 1] = arr[size - 1] / matrix[size - 1][size - 1];
	
	for (i = size - 2; i >= 0; i--)
	{
		x[i] = arr[i];
		for (j = i + 1; j < size; j++)
		{
			x[i] = x[i] - matrix[i][j] * x[j];
		}
		x[i] = x[i] / matrix[i][i];
	}
	
	cout << endl << "roots of equalations:" << endl;
	for (i = 0; i < size; i++)
	{
		cout << "x[" << i + 1 << "] = " << x[i] << endl;
	}
}

void deleteAll(double** matrix, double* arr, double* x)
{
	delete[] matrix;
	delete[] arr;
	delete[] x;
}

int main()
{
	int size, i, j;
	cout << "enter number of variables(number of equations also): ";
	cin >>size;
	double** matrix = new double* [size];
	double* arr = new double[size];
	double* x = new double[size];
	for (i = 0; i < size; i++)
	{
		matrix[i] = new double[size];
	}
	fillMatrix(matrix, arr, size);
	viewEqualations(matrix, arr, size);
	conversionMatrix(matrix, arr, size);
	solveEquations(matrix, arr, x, size);
	deleteAll(matrix, arr, x);
	return 0;
}