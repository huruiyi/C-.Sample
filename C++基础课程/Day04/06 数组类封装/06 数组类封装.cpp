#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyArray.h"

void test()
{
	MyArray arr(20);
	for (int i = 0; i < arr.capacity(); ++i)
	{
		arr.pushBack(i);
	}
	arr.foreach();
	cout << "------------" << endl;
	arr.popBack();
	arr.popFront();
	arr.foreach();
	cout << "------------" << endl;
	arr.insert(0, 200);
	arr.foreach();
	cout << "------------" << endl;
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}