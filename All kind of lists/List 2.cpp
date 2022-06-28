#include <iostream>
using namespace std;

struct stack
{
	int value;
	stack* adress;
};

stack* addStackBlock(stack* ultimate, int data)
{
	stack* block = new stack;
	block->value = data;
	block->adress = ultimate;
	return block;
}

void viewStack(stack* ultimate)
{
	while (ultimate != nullptr)
	{
		cout << ultimate->value << endl;
		ultimate = ultimate->adress;
	}
}

void deleteStack(stack* ultimate)
{
	stack* buffer;
	while (ultimate != nullptr)
	{
		buffer = ultimate;
		ultimate = ultimate->adress;
		delete buffer;
	}
}

int main()
{
	int i, data, size;
	stack* ultimate = nullptr;
	stack* secUltimate = nullptr;
	cout << "input number of stack's blocks: ";
	cin >> size;

	cout << "input elements:" << endl;
	for (i = 0; i < size; i++)
	{
		cin >> data;
		ultimate = addStackBlock(ultimate, data);
	}
	cout << "===========" << endl;
	cout << "your stack:" << endl;
	viewStack(ultimate);
	cout << "===========" << endl;

	stack* temp = ultimate;
	while (ultimate != nullptr)
	{
		secUltimate = addStackBlock(secUltimate, ultimate->value);
		ultimate = ultimate->adress;
	}
	cout << "changed stack:" << endl;
	viewStack(secUltimate);
	
	ultimate = temp;
	deleteStack(secUltimate);
	deleteStack(ultimate);
	return NULL;
}