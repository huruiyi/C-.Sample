#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void func() throw(int, char)
{
	throw (double)3.14;
}

int main() {
	try
	{
		func();
	}
	catch (double)
	{
		cout << "double�쳣��" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}