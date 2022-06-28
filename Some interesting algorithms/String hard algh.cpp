#include <iostream>
#include <string>

int main()
{
	int i, j, cnt1 = 0, cnt2 = 0, max = 0, i2 = 0, i3 = 0;
	char line[] = "baby angry zxc ahdbha yyy hhfs defence chicken";
	int length = strlen(line);
	std::cout << "string size: " << length << std::endl;

	for (i = 0; i < length; i++)
	{
		if (line[i] == ' ')
		{
			cnt1++;
		}
	}
	std::cout << cnt1 << std::endl;
	
	
	for (i = 0; i <= length; i++)
	{
		while (line[i] != ' ' && line[i] != '\0')
		{
			cnt2++;
			i++;
		}
		
		if (cnt2 > max) 
		{
			max = cnt2;
			cnt2 = 0;
		}
		
	}
	std::cout << max << std::endl;
	char** matrix = new char* [max];
	
	
	for (i = 0; i < max; i++)
	{
		matrix[i] = new char[cnt1];
	}

	for (i = 0; i < length; i++)
	{
		while (line[i] != ' ')
		{
			matrix[i2][i3] = line[i];
			i3++;
			i++;
		}
		matrix[i2][i3] = '\0';
		i2++;
		i3 = 0;
	}
	
	for (i = 0; i < i2; i++)
	{
		for (j = 0; matrix[i][j]!='\0'; j++)
		{
			std::cout << matrix[i][j];
		}
		printf("\n");
	}

	std::cout << std::endl;
	char* buffer;

	for (i = 0; i < i2; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			if (strcmp(matrix[i], matrix[j]) < 0)
			{
				buffer = matrix[i];
				matrix[i] = matrix[j];
				matrix[j] = buffer;
			}
		}
	}
	
	for (i = 0; i < i2; i++)
	{
		for (j = 0; matrix[i][j] != '\0'; j++)
		{
			std::cout << matrix[i][j];
		}
		printf("\n");
	}
	
	delete[] matrix;
	return 0;
}