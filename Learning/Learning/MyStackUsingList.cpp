#include "MyStackUsingList.h"

MyStackUsingList::MyStackUsingList(int size)
{
	top = -1;
	this->size = size;
	list = new MySinglyLinkedList();
}

MyStackUsingList::~MyStackUsingList()
{
}

void MyStackUsingList::push(int data)
{
	if (top < size - 1)
	{
		top++;
		list->insertAtEnd(data, false);

		cout << "\n" << data << " pushed to stack succesfully." << endl;
		printStackData();
	}
	else
	{
		cout << "\nStack is already full. Push operation failed.";
	}
}

int MyStackUsingList::pop()
{
	if (top > -1)
	{
		int temp = list->end->data;
		top--;
		list->deleteFromEnd(false);
		cout << "\n" << temp << " poped from stack succesfully." << endl;
		printStackData();
		return temp;
	}
	else
	{
		cout << "\nStack is already empty. Pop operation failed.";
		return -1;
	}
}

void MyStackUsingList::printStackData() const
{
	cout << "\nHere is the stack data" << endl;
	list->printList();
}