#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数!" << endl;
	}

	Person(int, int)
	{
		cout << "Person有参构造函数!" << endl;
	}

	Person(const Person& person)
	{
		cout << "Person拷贝构造函数!" << endl;
	}

	~Person()
	{
		cout << "Person析构函数" << endl;
	}
public:
	char* pName;
};

//对象以值传递的方式传给函数参数

void doLogic(Person person)
{
}

void test01()
{
	Person person;
	doLogic(person);
}

//函数局部对象以值传递的方式从函数返回(vs debug模式下调用一次拷贝构造，qt不调用任何构造)
//RVO

Person CreatePerson()
{
	cout << "-----------------" << endl;
	Person person;
	cout << "CreatePerson:" << (int)& person << endl;
	return person;
}

void test02()
{
	Person person = CreatePerson();
	cout << "-----------------" << endl;
	cout << "test02:" << (int)& person << endl;
}

#if 0
void CreatePerson(Person* person)
{
	//对person构造
	*person

		return;
}
void test02()
{
	//只是分配内存
	Person person;
	CreatePerson(person);
	cout << (int)& person << endl;
}
#endif

//用一个对象初始化另一个对象
void test03()
{
	Person p1;
	Person p2 = p1;
	Person p3(p2);
	//p2 = p1;

	//1. 如果对象没有创建，那么=号表示拷贝构造函数调用
	//2. 如果对象已经创建完毕，那么=号表示赋值行为
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}