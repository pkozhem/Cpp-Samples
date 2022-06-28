/*How to create and use Lists*/
#include <iostream>
using namespace std;

struct list
{
	int data;
	list* next;
	list* prev;
};

list* createList(list* head, list* tail)
{
	list* block = new list;
	int data;
	cout << "enter root block data: ";
	cin >> data;
	block->data = data;
	block->next = nullptr;
	block->prev = nullptr;
	head = tail = block;
	return block;
}

list* addHead(list* head)
{
	list* block = new list;
	int data;
	cout << "enter head data: ";
	cin >> data;
	block->data = data;
	block->prev = nullptr;
	head->prev = block;
	block->next = head;
	return block;
}

list* addTail(list* tail)
{
	list* block = new list;
	int data;
	cout << "enter tail data: ";
	cin >> data;
	block->data = data;
	block->next = nullptr;
	tail->next = block;
	block->prev = tail;
	return block;
}

void viewList(list* head)
{
	while (head != nullptr)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}

int main()
{
	list* head = nullptr;
	list* tail = nullptr;
	createList(head, tail);
	addHead(head);
	addTail(tail);
	viewList(head);
}