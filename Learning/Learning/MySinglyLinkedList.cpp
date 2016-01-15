#include <iostream>
#include "MySinglyLinkedList.h"
using namespace std;

MySinglyLinkedList::MySinglyLinkedList()
	{
		begin = nullptr;
		end = nullptr;
		len = 0;
	}

MySinglyLinkedList::~MySinglyLinkedList()
{
	
}

void MySinglyLinkedList::printList() const
{
	if (len == 0)
		cout << "List is empty\n";

	Node* temp = begin;

	for (size_t i = 1; i <= len; i++)
	{
		cout << temp->data;
		if (i != len)
			cout << " -> ";
		temp = temp->link;
	}
}

void MySinglyLinkedList::insertAtBegining(int data, bool printInfo)
{

	if (printInfo)
		cout << "\nInserting " << data << " at the begining" << endl;

	Node* nodeToInsert = new Node(data);
	if (len == 0)
	{
		begin = nodeToInsert;
		end = nodeToInsert;
	}
	else
	{
		nodeToInsert->link = begin;
		begin = nodeToInsert;
	}

	len++;
	if (printInfo)
	{
		cout << "\nThe list after insertion is : ";
		printList();
	}
}

void MySinglyLinkedList::insertAtBegining(int data)
{
	insertAtBegining(data, true);
}


void MySinglyLinkedList::insertAtEnd(int data, bool printInfo)
{
	if (printInfo)
		cout << "\nInserting " << data << " at the end" << endl;

	Node* nodeToInsert = new Node(data);
	if (len == 0)
	{
		begin = nodeToInsert;
		end = nodeToInsert;
	}
	else
	{
		end->link = nodeToInsert;
		end = nodeToInsert;
	}

	len++;
	if (printInfo)
	{
		cout << "\nThe list after insertion is : ";
		printList();
	}
}
	
void MySinglyLinkedList::insertAtEnd(int data)
{
	insertAtEnd(data, true);
}

void MySinglyLinkedList::insertAtPosition(int data, int position, bool printInfo)
{

	if (printInfo)
		cout << "\nInserting " << data << " at the position " << position << endl;

	if (position >= len + 1)
		insertAtEnd(data, false);
	else if (position <= 1)
		insertAtBegining(data, false);
	else
	{
		Node* nodeToInsert = new Node(data);
		Node* temp = begin;

		for (size_t i = 1; i < position - 1; i++)
		{
			temp = temp->link;
		}

		nodeToInsert->link = temp->link;
		temp->link = nodeToInsert;

		len++;
	}

	if (printInfo)
	{
		cout << "\nThe list after insertion is : ";
		printList();
	}
}

void MySinglyLinkedList::insertAtPosition(int data, int position)
{
	insertAtPosition(data, position, true);
}


void MySinglyLinkedList::deleteFromBegining(bool printInfo)
{

	if (printInfo)
		cout << "\nDeleting from the begining" << endl;
	if (len == 0)
	{
		cout << "\nList is already empty. Deletion can't be performed. Please insert some element first." << endl;
		return;
	}
	else if (len == 1)
	{
		delete begin;
		begin = nullptr;
		end = nullptr;
	}
	else
	{
		Node* temp = begin;
		begin = begin->link;
		delete temp;
	}

	len--;

	if (printInfo)
	{
		cout << "\nThe list after deletion is : ";
		printList();
	}
}

void MySinglyLinkedList::deleteFromBegining()
{
	deleteFromBegining(true);
}

void MySinglyLinkedList::deleteFromEnd(bool printInfo)
{

	if (printInfo)
		cout << "\nDeleting from the end" << endl;
	if (len == 0)
	{
		cout << "\nList is already empty. Deletion can't be performed. Please insert some element first." << endl;
		return;
	}
	else if (len == 1)
	{
		delete end;
		begin = nullptr;
		end = nullptr;
	}
	else
	{
		Node* temp = begin;
		for (size_t i = 1; i < len - 1; i++)
		{
			temp = temp->link;
		}
		end = temp;
		delete temp->link;
	}

	len--;

	if (printInfo)
	{
		cout << "\nThe list after deletion is : ";
		printList();
	}
}

void MySinglyLinkedList::deleteFromEnd()
{
	deleteFromEnd(true);
}


void MySinglyLinkedList::deleteAtPosition(int position, bool printInfo)
{

	if (printInfo)
		cout << "\nDeleting node at position " << position << endl;
	if (len == 0)
	{
		cout << "\nList is already empty. Deletion can't be performed. Please insert some element first." << endl;
		return;
	}
	else if (position <= 1)
	{
		deleteFromBegining(false);
	}
	else if (position >= len)
	{
		deleteFromEnd(false);
	}
	else
	{
		Node* temp = begin;
		for (size_t i = 1; i < position - 1; i++)
		{
			temp = temp->link;
		}

		Node* nodeToDelete = temp->link;
		temp->link = nodeToDelete->link;

		delete nodeToDelete;
		len--;
	}

	if (printInfo)
	{
		cout << "\nThe list after deletion is : ";
		printList();
	}
}

void MySinglyLinkedList::deleteAtPosition(int position)
{
	deleteAtPosition(position, true);
}

void MySinglyLinkedList::deleteData(int data, bool printInfo)
{
	if (printInfo)
		cout << "\nDeleting data " << data << " from the list" << endl;
	if (len == 0)
	{
		cout << "\nList is already empty. Deletion can't be performed. Please insert some element first." << endl;
		return;
	}
	else
	{
		int pos = getPositionInTheList(data);

		if (pos != -1)
		{
			deleteAtPosition(pos, false);
		}
		else
		{
			printInfo = false;
			cout << "Data to be deleted not present in the list." << endl;
		}
	}

	if (printInfo)
	{
		cout << "\nThe list after deletion is : ";
		printList();
	}
}

void MySinglyLinkedList::deleteData(int data)
{
	deleteData(data, true);
}

int MySinglyLinkedList::getPositionInTheList(int data) const
{
	Node* temp = begin;

	if (temp->data == data)
	{
		return 1;
	}

	for (size_t i = 1; i < len; i++)
	{
		temp = temp->link;
		if (temp->data == data)
		{
			return i + 1;
		}
	}

	return -1;
}