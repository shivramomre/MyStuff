#pragma once

class Node
{
public :
	int data;
	Node* link;

	Node()
	{
		data = -1;
		link = nullptr;
	}

	Node(int data)
	{
		this->data = data;
		link = nullptr;
	}
};

class MySinglyLinkedList
{
public:
	Node* begin;
	Node* end;
	int len;

	MySinglyLinkedList();
	~MySinglyLinkedList();

	void printList(void) const;
	void insertAtBegining(int data, bool printInfo);
	void insertAtBegining(int data);
	void insertAtEnd(int data, bool printInfo);
	void insertAtEnd(int data);
	void insertAtPosition(int data, int position, bool printInfo);
	void insertAtPosition(int data, int position);
	void deleteFromBegining(bool printInfo);
	void deleteFromBegining(void);
	void deleteFromEnd(bool printInfo);
	void deleteFromEnd(void);
	void deleteAtPosition(int position, bool printInfo);
	void deleteAtPosition(int position);
	void deleteData(int data, bool printInfo);
	void deleteData(int data);
	int getPositionInTheList(int data) const;
};

