#include "MyStack.h"

MyStack::MyStack(int size)
{
	top = -1;
	this->size = size;
	arr = new int[size];
}

MyStack::~MyStack()
{
}

void MyStack::push(int data)
{
	if(top < size-1)
	{
		top++;
		arr[top] = data;

		cout << "\n" << data << " pushed to stack succesfully." << endl;
		printStackData();
	}
	else
	{
		cout << "\nStack is already full. Push operation failed.";
	}
}

int MyStack::pop()
{
	if(top > -1)
	{
		int temp = arr[top];
		top--;
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

void MyStack::printStackData() const
{
	cout << "\nHere is the stack data" << endl;
	for (int i = 0; i <= top; i++)
	{
		cout << arr[i] << " ";
	}
}

