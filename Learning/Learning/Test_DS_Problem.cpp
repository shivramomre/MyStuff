#include <gtest/gtest.h>
#include "MySinglyLinkedList.h"
#include "DS_Problem.h"

TEST(DS_Problems, Reverse_Singly_Linked_List)
{
	MySinglyLinkedList* list = new MySinglyLinkedList();

	list->insertAtEnd(10);
	list->insertAtEnd(20);
	list->insertAtEnd(30);
	list->insertAtEnd(40);
	list->insertAtEnd(50);
	list->insertAtEnd(60);
	list->insertAtEnd(70);

	Node* rev_list = DS_Problem::reverse_singly_linked_list(list->begin);
	cout << "\nAfter reversing the list" << endl;
	DS_Problem::print_singly_linked_list(rev_list);
}