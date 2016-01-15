#include <gtest/gtest.h>
#include "MySinglyLinkedList.h"

TEST(Test_MySinglyLinkedList, All_cases)
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