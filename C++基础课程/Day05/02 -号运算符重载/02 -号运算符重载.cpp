#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student
{
public:
	Student(int c) :mC(c) {}
public:
	int mC;
};

class Person
{
public:
	Person(int a, int b) :mA(a), mB(b) {}
	Person operator-(const Student &stu)
	{
		Person ret(this->mA - stu.mC, this->mB - stu.mC);
		return ret;
	}
public:
	int mA;
	int mB;
};

void test()
{
	Person person(100, 200);
	Student stu(10);

	Person ret = person - stu; //person.operator-(stu);
	cout << ret.mA << " " << ret.mB << endl;
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}