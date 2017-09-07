#include<iostream>
#include<string>
#include "MyArray.h"

void 大括号运算符重载()
{
	MyArray arr = { 1,2,3,4,5,6,7,8,9 };
	arr.foreach();
}
void  加等于运算符重载()
{
	MyArray arr;
	arr += 1, 2, 3, 4, 5, 6, 7, 8, 9;
	arr.foreach();
}

int main()
{
	大括号运算符重载();
	加等于运算符重载();
	return 0;
}