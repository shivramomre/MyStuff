#pragma once
#include <iostream>
#include "MySinglyLinkedList.h"
using namespace std;

class DS_Problem
{
public:
	DS_Problem();
	~DS_Problem();

	static Node* reverse_singly_linked_list(Node* begin);
	static void print_singly_linked_list(Node* begin);
};

