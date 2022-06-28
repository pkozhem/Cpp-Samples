#include <iostream>
using namespace std;

struct list
{
	int data;
	list* next;
	list* prev;
};

list* addHead(list* current, int value)
{
	list* block = new list;
	current->prev = block;
	block->prev = nullptr;
	block->next = current;
	block->data = value;
	return block;
}

list* addTail(list* current, int value)
{
	list* block = new list;
	current->next = block;
	block->next = nullptr;
	block->prev = current;
	block->data = value;
	return block;
}

void circleLink(list* head, list* tail)
{
	head->prev = tail;
	tail->next = head;
}

void uncircleLink(list* head, list* tail)
{
	head->prev = nullptr;
	tail->next = nullptr;
}

void deleteList(list* head, int counter)
{
	int k = 0;
	list* buffer;
	while (k != counter)
	{
		buffer = head;
		head = head->next;
		delete buffer;
		k++;
	}
}

void viewUnlinkedListFromHead(list* head, int counter)
{
	int k = 0;
	while (k != counter)
	{
		cout << head->data << ' ';
		head = head->next;
		k++;
	}
}

void movedView(list** current, list* head, int counter)
{
	int choose , i;
	while (true)
	{
		cout << "the list: ";
		viewUnlinkedListFromHead(head, counter);
		cout << endl << "current element: " << (*current)->data << endl;
		cout << "choose '1' move right from current\nchoose '2' move left from current\nchoose '3' exit from navigation" << endl;
	Try:
		cout << "     your choice: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "next to right element: " << ((*current)->next)->data << endl;
			(*current) = (*current)->next;
			break;

		case 2:
			cout << "next to left element: " << ((*current)->prev)->data << endl;
			(*current) = (*current)->prev;
			break;

		case 3:
			return;

		default:
			cout << "choose 1, 2, or 3" << endl;
			goto Try;
		}
	}
}

void Menu()
{
	cout << "\t\tDOUBLY LINKED LIST MENU" << endl;
	cout << "1 - create root block and enter value" << endl;
	cout << "2 - add head block and enter value" << endl;
	cout << "3 - add tail block and enter value" << endl;
	cout << "4 - circle link the list" << endl;
	cout << "5 - navigate through the list(work if list is circle linked)" << endl;
	cout << "6 - uncircle link(create the list initial)" << endl;
	cout << "7 - view list(if it circle unlinked)" << endl;
	cout << "8 - clean console" << endl;
	cout << "9 - delete list and finish the program" << endl;
}

int main()
{
	list* head = new list;
	list* tail = new list;
	list* root = new list;
	list* bufferHead = new list;
	list* bufferTail = new list;
	int counter = 0, condHead = 0, condTail = 0, condRoot = 0, condLink = 0, condAll = 0, condCH = 0, condCT = 0;
	int value, i, sW;
	Menu();

	while (true)
	{
		cout << endl << "your choice: ";
		cin >> sW;
		switch (sW)
		{
		case 1:
			if (condRoot == 0)
			{
				cout << "enter value: ";
				cin >> value;
				root->data = value;
				counter++;
				condRoot = 1;
				condAll = 1;
			}
			else
			{
				cout << "you've already created root block" << endl;
			}
			break;

		case 2:
			cout << "enter value: ";
			if (condHead == 0 && condAll == 1)
			{
				cin >> value;
				head = addHead(root, value);
				bufferHead = head;
				counter++;
				condHead = 1;
				condCH = 1;
			}
			else if (condHead == 1 && condAll == 1)
			{
				cin >> value;
				head = addHead(head, value);
				bufferHead = head;
				condCH = 1;
				counter++;
			}
			else
			{
				cout << "create root block firstly" << endl;
			}
			break;

		case 3:
			cout << "enter value: ";
			if (condTail == 0 && condAll == 1)
			{
				cin >> value;
				tail = addTail(root, value);
				bufferTail = tail;
				counter++;
				condTail = 1;
				condCT = 1;
			}
			else if (condTail == 1 && condAll == 1)
			{
				cin >> value;
				tail = addTail(tail, value);
				bufferTail = tail;
				condCT = 1;
				counter++;
			}
			else
			{
				cout << "create root block firstly" << endl;
			}
			break;

		case 4:
			if (condAll == 1)
			{
				if (condCH == 1 && condCT == 1)
				{
					circleLink(head, tail);
				}
				else if (condCH == 1 && condCT == 0)
				{
					circleLink(head, root);
				}
				else if (condCH == 0 && condCT == 1)
				{
					circleLink(root, tail);
				}
				else
				{
					cout << "add blocks firstly" << endl;
				}
				condLink = 1;
			}
			else
			{
				cout << "create root block firstly" << endl;
			}
			break;

		case 5:
			if (condAll == 1 && condLink == 1 && condCH == 1)
			{
				movedView(&head, bufferHead, counter);
			}
			else if (condAll == 1 && condLink == 1 && condCH == 0)
			{
				movedView(&root, bufferTail, counter);
			}
			else if (condAll == 1 && condLink == 0)
			{
				cout << "link the list firstly" << endl;
			}
			else
			{
				cout << "create root block firstly" << endl;
			}
			break;

		case 6:
			if (condAll == 1 && condLink == 1 && condCH == 1 && condCT == 1)
			{
				uncircleLink(head, tail);
				head = bufferHead;
				tail = bufferTail;
				condLink = 0;
			}
			else if (condAll == 1 && condLink == 1 && condCH == 1 && condCT == 0)
			{
				uncircleLink(head, root);
				head = bufferHead;
				root = bufferTail;
				condLink = 0;
			}
			else if (condAll == 1 && condLink == 1 && condCH == 0 && condCT == 1)
			{
				uncircleLink(root, tail);
				root = bufferHead;
				tail = bufferTail;
				condLink = 0;
			}
			else
			{
				cout << "not enough conditions" << endl;
			}
			break;
		
		case 7:
			if (condAll == 1 && condLink == 0 && condCH == 1)
			{
				viewUnlinkedListFromHead(head, counter);
			}
			else if (condAll == 1 && condLink == 0 && condCT == 1)
			{
				viewUnlinkedListFromHead(root, counter);
			}
			else
			{
				cout << "not enough conditions" << endl;
			}
			break;

		case 8:
			system("cls");
			Menu();
			break;

		case 9:
			if (condAll == 1 && condCH == 1)
			{
				deleteList(head, counter);
			}
			else if (condAll == 1 && condCH == 0)
			{
				deleteList(root, counter);
			}
			return 0;
		}
	}
	return 0;
}