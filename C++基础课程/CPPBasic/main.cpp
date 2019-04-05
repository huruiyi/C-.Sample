#include<iostream>
using namespace std;
int wmain()
{
	for (size_t i = 0; i < 10; i++)
	{
		static  int a = 0;
		cout << a << endl;
		a++;
		cout << a << endl;
	}
	return 0;
}