#include "DS_Problem.h"

DS_Problem::DS_Problem()
{
}

DS_Problem::~DS_Problem()
{
}

Node* DS_Problem::reverse_singly_linked_list(Node* begin)
{
	Node* reversed_node = nullptr;

	if(begin == nullptr)
	{
		return nullptr;
	}

	else if(begin->link == nullptr)
	{
		return begin;
	}

	else
	{
		Node* first_node = begin;
		Node* second_node = first_node->link;
		Node* third_node = second_node->link;
	
		first_node->link = nullptr;
		second_node->link = first_node;

		while(third_node != nullptr)
		{
			first_node = second_node;
			second_node = third_node;
			third_node = second_node->link;

			second_node->link = first_node;
		}

		reversed_node = second_node;
	}
	return reversed_node;
}

void DS_Problem::print_singly_linked_list(Node* begin)
{
	cout << "\nHere is the list : ";
	Node* temp = begin;
	if(temp != nullptr)
	{
		while(temp != nullptr)
		{
			cout << temp->data;
			if(temp->link != nullptr)
				cout << " -> ";
			temp = temp->link;
		}
	}
}
