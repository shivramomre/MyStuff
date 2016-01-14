#include <iostream>
#include <gtest/gtest.h>

using namespace std;

struct BankAccount
{
	int balance = 0;

	BankAccount()
	{
	}

	explicit BankAccount(const int balance) : balance{ balance }
	{
	}

	void deposite(int amount)
	{
		balance += amount;
	}

	bool withdrawl(int amount)
	{
		if (amount <= balance)
		{
			balance -= amount;
			return true;
		}
		else
			return false;
	}
};

struct BankAccountTest : testing::Test
{
	BankAccount* account;

	BankAccountTest()
	{
		account = new BankAccount();
	}

	~BankAccountTest()
	{
		delete account;
	}
};

TEST_F(BankAccountTest, Test_account_when_empty)
{
	EXPECT_EQ(0, account->balance);
}

TEST_F(BankAccountTest, Can_deposit_amount)
{
	account->deposite(100);
	EXPECT_EQ(100, account->balance);
	account->deposite(20);
	EXPECT_EQ(120, account->balance);
}

TEST_F(BankAccountTest, Can_withdrawl_amount)
{
	account->deposite(100);
	EXPECT_EQ(100, account->balance);
	account->withdrawl(50);
	EXPECT_EQ(50, account->balance);
	account->deposite(20);
	EXPECT_EQ(70, account->balance);
}


struct Account_state
{
	int initial_balance;
	int withdrawl_amount;
	int final_balance;
	bool success;

	friend std::ostream& operator<<(std::ostream& os, const Account_state& obj)
	{
		return os
			<< "initial_balance: " << obj.initial_balance
			<< " withdrawl_amount: " << obj.withdrawl_amount
			<< " final_balance: " << obj.final_balance
			<< " success: " << obj.success;
	}
};

struct AmountWithDrawlTest : BankAccountTest, testing::WithParamInterface<Account_state>
{
	AmountWithDrawlTest()
	{
		account->balance = GetParam().initial_balance;
	}
};

TEST_P(AmountWithDrawlTest, Final_Balance)
{
	auto as = GetParam();
	auto success = account->withdrawl(as.withdrawl_amount);
	EXPECT_EQ(account->balance, as.final_balance);
	EXPECT_EQ(success, as.success);
}

INSTANTIATE_TEST_CASE_P(Default, AmountWithDrawlTest,
	testing::Values(
		Account_state{ 100,50,50, true },
		Account_state{ 100,20,80, true },
		Account_state{ 100,200,100, false }
	));

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}