#include <iostream>
#include <string>
using namespace std;

int my_main()
{
	while (1)
	{
		cout << "Below are the things you can do with this project." << endl;
		cout << "Choose the option" << endl;

		cout << "1. DataStructure" << endl;
		cout << "0. Exit" << endl;

		int val;
		cin >> val;

		if (val == 1)
		{
			cout << "Below are the things you can do with Datastructure." << endl;
			cout << "1. SinglyLinkedList";
			cout << "0. Exit" << endl;
			cout << "Choose the option" << endl;

			int dsVal;
			cin >> dsVal;

			if(dsVal == 1)
			{
				
			}
			else if (val == 0)
			{
				break;
			}
			else
			{
				cout << "Invalid input provided. You want to continue again ? y/n : ";
				char choice;
				cin >> choice;

				if (choice == 'n' || choice == 'N')
					break;
			}
		}
		else if (val == 0)
		{
			break;
		}
		else
		{
			cout << "Invalid input provided. You want to continue again ? y/n : ";
			char choice;
			cin >> choice;

			if (choice == 'n' || choice == 'N')
				break;
		}
	}
	return 0;
}