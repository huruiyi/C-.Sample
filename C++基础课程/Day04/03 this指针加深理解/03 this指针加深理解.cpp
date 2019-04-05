#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int mA)
	{
		this->mA = mA;
		mB = 100;
	}

	void printPerson() const
	{
	}

	//常函数的const修饰的是成员函数的this指针
	//表示函数内部不会通过this指针修改this指针指向空间的值
	//如果说变量是mutable修饰的，那么不受常函数限制
	void showPerson() const
	{
		if (this == NULL)
		{
			return;
		}
		cout << "hello world:" << this->mA << endl;

		//this->mA = 100;
		//this = NULL;
		//const Person *const this;

		this->mB = 200;
	}

public:
	int mA;
	mutable int mB;
};

//类的成员函数内部，this可加也可不加
//如果形参变量名和成员变量名冲突，加上this区分

void test()
{
	Person* person = new Person(10);
	person->showPerson();
	//showPerson(person);

	delete person;
}

//常量对象
void test02()
{
	const Person person(10);

	//常对象可以访问成员变量，但是不能修改成员变量，除了mutable修饰的成员变量
	//常对象只能调用常函数
	//如果对象用const修饰，表示对象不会修改，对象只能调用用const修饰的成员函数

	person.printPerson();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}