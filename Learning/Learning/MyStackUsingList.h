#pragma once
#include "MySinglyLinkedList.h"
#include "BaseHeader.h"

class MyStackUsingList
{
public:
	int size;
	int top;
	MySinglyLinkedList* list;

	MyStackUsingList(int size);
	~MyStackUsingList();	
	
	void push(int data);
	int pop(void);
	void printStackData(void) const;
};

