#include <iostream>
#include <gtest/gtest.h>
using namespace std;

struct Node
{
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
public :
	Node* begin;
	Node* end;
	int len;

	MySinglyLinkedList()
	{
		begin = nullptr;
		end = nullptr;
		len = 0;
	}

	void printList(void)
	{
		if(len == 0)
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

	void insertAtBegining(int data, bool printInfo)
	{
		if(printInfo)
			cout << "\nInserting " << data << " at the begining" << endl;

		Node* nodeToInsert = new Node(data);
		if(len == 0)
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

	void insertAtEnd(int data, bool printInfo)
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

	void insertAtPosition(int data, int position, bool printInfo)
	{
		if(printInfo)
			cout << "\nInserting " << data << " at the position " << position << endl;

		if (position >= len + 1)
			insertAtEnd(data, false);
		else if (position <= 1)
			insertAtBegining(data, false);
		else
		{
			Node* nodeToInsert = new Node(data);
			Node* temp = begin;

			for (size_t i = 1; i < position-1; i++)
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

	void deleteFromBegining(bool printInfo)
	{
		if(printInfo)
			cout << "\nDeleting from the begining" << endl;
		if (len == 0)
		{
			cout << "\nList is already empty. Deletion can't be performed. Please insert some element first." << endl;
			return;
		}
		else if(len == 1)
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

	void deleteFromEnd(bool printInfo)
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
			for (size_t i = 1; i < len-1; i++)
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

	void deleteAtPosition(int pos, bool printInfo)
	{
		if (printInfo)
			cout << "\nDeleting node at position "<< pos << endl;
		if (len == 0)
		{
			cout << "\nList is already empty. Deletion can't be performed. Please insert some element first." << endl;
			return;
		}
		else if (pos <= 1)
		{
			deleteFromBegining(false);
		}
		else if(pos >= len)
		{
			deleteFromEnd(false);
		}
		else
		{
			Node* temp = begin;
			for (size_t i = 1; i < pos-1; i++)
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

	void deleteData(int data, bool printInfo)
	{
		if (printInfo)
			cout << "\nDeleting data "<< data << " from the list" << endl;
		if (len == 0)
		{
			cout << "\nList is already empty. Deletion can't be performed. Please insert some element first." << endl;
			return;
		}
		else
		{
			int pos = getPositionInTheList(data);
			
			if(pos != -1)
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

	private:
		int getPositionInTheList(int data)
		{
			Node* temp = begin;

			if(temp->data == data)
			{
				return 1;
			}

			for (size_t i = 1; i < len; i++)
			{
				temp = temp->link;
				if (temp->data == data)
				{
					return i+1;
				}
			}

			return -1;
		}
};

TEST(Test_MySinglyLinkedList, Test_add_at_begin)
{
	MySinglyLinkedList* list = new MySinglyLinkedList();
	list->printList();
	list->deleteFromBegining(true);

	list->insertAtBegining(10, true);
	list->deleteFromBegining(true);
	list->insertAtBegining(5, true);
	list->insertAtBegining(50, true);
	list->insertAtBegining(200, true);

	list->insertAtEnd(500, true);
	list->insertAtEnd(400, true);
	list->insertAtEnd(600, true);

	list->insertAtPosition(1000, 5, true);
	list->insertAtPosition(2000, 5, true);
	list->insertAtPosition(3000, 5, true);
	list->insertAtPosition(4000, 15, true);
	list->insertAtPosition(5000, -5, true);

	list->deleteFromBegining(true);
	list->deleteFromBegining(true);
	list->deleteFromBegining(true);

	list->deleteFromEnd(true);
	list->deleteFromEnd(true);
	list->deleteFromEnd(true);

	list->deleteAtPosition(3, true);
	list->deleteAtPosition(3, true);
	list->deleteAtPosition(3, true);
	list->deleteAtPosition(3, true);

	list->insertAtEnd(10, true);
	list->insertAtEnd(20, true);
	list->insertAtEnd(30, true);
	list->insertAtEnd(40, true);
	list->insertAtEnd(50, true);
	
	list->deleteData(100, true);
	list->deleteData(30, true);
	list->deleteData(30, true);
	list->deleteData(10, true);
	list->deleteData(50, true);
}