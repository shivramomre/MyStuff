#include "BaseHeader.h"
#include "MyStack.h"
#include "MyStackUsingList.h"

TEST(MyStackTest, All)
{
	MyStack stack(5);

	stack.pop();
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);
	stack.push(70);
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
}

TEST(MyStackUsingListTest, All)
{
	MyStackUsingList stack(5);

	stack.pop();
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);
	stack.push(70);
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
}