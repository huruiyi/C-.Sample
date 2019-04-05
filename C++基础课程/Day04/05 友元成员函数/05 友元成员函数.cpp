#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person;

class GirlFriend
{
public:
	void talk(Person& person);

	void beat(Person& person);
};

class Person
{
	friend void GirlFriend::beat(Person& person);
private:
	string mName;
};

void GirlFriend::talk(Person& person)
{
}

void GirlFriend::beat(Person& person)
{
	person.mName;
}

//当我们使用类的成员的时候，编译器必须先看到类的结构
//如果编译器只看到类声明，我们可以定义一个引用或者指针

int main() {
	system("pause");
	return EXIT_SUCCESS;
}