#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
	int size;
	printf("enter array size: ");
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		cin >> arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				arr[j] = 0;
			}
		}
	}

	cout << endl << endl << endl;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i; j < size; j++)
			{
				if (arr[j] != 0)
				{
					swap(arr[j], arr[i]);
					break;
				}
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			cnt++;
		}
	}

	for (int i = 0; i < size - cnt; i++)
	{
		cout << i + 1 << ") " << arr[i] << endl;
	}
	
	delete[]arr;
	return 0;

}