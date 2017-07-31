#include <iostream>
#include <string>
using namespace std;

void IntRefenceDemo()
{
	int a = 10;
	int &b = a;
	int &c = b;
	//a,b,c指的都是同一块空间
	b = 100;
	cout << "a= " << a << "------&a=" << &a << endl;
	cout << "b= " << b << "------&b=" << &b << endl;
	cout << "c= " << c << "------&c=" << &c << endl;
}

#if 0

struct Person
{
	string Name;
	int Age;
};

void ShowPerson(const Person &person)
{
	cout << person.Name << "  " << person.Age << endl;
}
void ChagePerson(Person &person)
{
	person.Name = "BBB";
}
void StructDemo()
{
	Person p{ "AAA",20 };
	ShowPerson(p);
	ChagePerson(p);
	ShowPerson(p);
}
#endif // 0

int &  RturnRefence()
{
	//static 的生命周期
	//int a = 123;
	static int a = 123;
	return  a;
}

void RturnRefenceDemo()
{
	int &a = RturnRefence();
	RturnRefence() = 456;
	cout << "&a   =      " << a << endl;
}

void ArrayRefenceDemo()
{
#if 0
	int arr[10] = { 1,2,3,4,5,6,7,8,9, 0 };
	int(*parr)[10] = &arr;
	for (int i = 0; i < 10; i++)
	{
		parr[0][i] = parr[0][i] + 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << parr[0][i] << endl;
	}
#endif

	int arr[10];
	int(&pArr)[10] = arr;
	pArr[0] = 123;
	cout << "arr[0]= " << arr[0] << endl;

	typedef int(ARR_TYPE)[10];
	ARR_TYPE &arrRef = arr;
	arrRef[1] = 456;
	cout << "arr[0]= " << arrRef[0] << endl;
	cout << "arr[1]= " << arrRef[1] << endl;
}