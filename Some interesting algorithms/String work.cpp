#include <iostream>
using namespace std;

int main()
{
	int size, i, cnt = 0, i2 = 0;
	bool cond = 0;
	char line[] = "mid or first pick techies";
	int lenght = strlen(line);
	printf(line);
	printf("\nenter size of first substring: ");
	cin >> size;
	
	for (i = 0; i <= size; i++)
	{
		if (line[i] == ' ')
		{
			cond = 1;
			break;
		}
	}
	
	if (cond == 1 && size >= 0 && size <= lenght)
	{
		if (line[size] != ' ')
		{
			while (line[size - cnt - 1] != ' ')
			{
				cnt++;
			}
		}
		cout << line[size] << " - your line[size] element." << endl;
		cout << cnt << " - the number of  elements facing the line[size] element till 1st space." << endl;
		
		char* sub1Line = new char[size - cnt];
		char* sub2Line = new char[lenght - size + cnt];

		for (i = 0; i < size - cnt; i++)
		{
			sub1Line[i] = line[i];
		}

		for (i = size - cnt; i < lenght; i++)
		{
			sub2Line[i2] = line[i];
			i2++;
		}

		for (i = 0; i < size - cnt; i++)
		{
			cout << sub1Line[i];
		}

		printf("\n");

		for (i = 0; i < lenght - size + cnt; i++)
		{
			cout << sub2Line[i];
		}

		delete[] sub1Line;
		delete[] sub2Line;
	}
	
	else if (cond == 0 && size >= 0 && size <= lenght)
	{
		cout << "line[size] - " << line[size] << ". so: \n";
		printf(line);
	}
	
	else if (size < 0)
	{
		printf("negative size.\n");
	}
	
	else if (size > lenght)
	{
		printf("too big size.\n");
	}
	return 0;
}