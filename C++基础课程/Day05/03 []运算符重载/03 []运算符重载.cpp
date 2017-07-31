#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyArray.h"

void test01()
{
	MyArray arr;
	arr[0] = 100;
	int a = arr[0];
	cout << "arr[0] = " << arr[0] << endl;
}

void test02()
{
	MyArray arr = { 10, 20, 30, 40 };
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void func(initializer_list<int> list)
{
}

int main() {
	//test02();

	func({ 1, 2, 3, 4, 5, 6, 6, 7, 8 });

	system("pause");
	return EXIT_SUCCESS;
}