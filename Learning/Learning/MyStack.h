#pragma once
#include "BaseHeader.h"

class MyStack
{
public:
	int size;
	int top;
	int* arr;

	MyStack(int size);
	~MyStack();

	void push(int data);
	int pop(void);
	void printStackData(void) const;
};

