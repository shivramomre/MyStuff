#include <gtest\gtest.h>
#include <iostream>

using namespace std;

class BankAccount
{
public : 
	int balance = 0;

	BankAccount()
	{
	}

	BankAccount(int balance)
	{
		balance = balance;
	}

	void printData()
	{
		cout << "The balance is : " << balance;
	}
};

TEST(AccountTest, BankAccountStartsEmpty)
{
	BankAccount bank_account;
	EXPECT_EQ(0, bank_account.balance);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}