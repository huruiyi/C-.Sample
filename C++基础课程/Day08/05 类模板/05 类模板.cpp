#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray()
	{
		pAddress = new T[10];
	}
public:
	T* pAddress;
	int mSize;
};

void test()
{
	//类模板不支持自动类型推导
	MyArray<int> arr;
}

//类模板当做函数参数
template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		mName = name;
		mAge = age;
	}
public:
	NameType mName;
	AgeType mAge;
};

void printPerson(Person<string, int>& person)
{
	cout << "Name:" << person.mName << " Age:" << person.mAge << endl;
}

template<class T>
void showPerson(T& person)
{
	cout << typeid(T).name() << endl;
	cout << "Name:" << person.mName << " Age:" << person.mAge << endl;
}

template<class NameType, class AgeType>
void lookPerson(Person<NameType, AgeType>& person)
{
	cout << typeid(NameType).name() << endl;
	cout << typeid(AgeType).name() << endl;
	cout << "Name:" << person.mName << " Age:" << person.mAge << endl;
}

void test02()
{
	Person<string, int> person("aaa", 10);
	//printPerson(person);
	showPerson(person);
	lookPerson(person);
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}