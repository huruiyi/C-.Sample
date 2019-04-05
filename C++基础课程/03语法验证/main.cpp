#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

void test0()
{
	int a = 123;
	int* p = &a;
	int& r = a;
}
void test1()
{
	const char const* const p1 = "p1 Hello World";
	printf("%p-%s\n", p1, p1);

	const char const* p2 = "p2 Hello World";
	printf("%p-%s\n", p2, p2);

	const char* p3 = "p3 Hello World";
	printf("%p-%s\n", p3, p3);

	char* p4 = "p4 Hello World";
	printf("%p-%s\n", p4, p4);
}

void test2()
{
	int a = 123;
	int& ra = a;
	int b = ra;
	cout << b;
}
int main()
{
	test0();
	system("pause");
	return 0;
}