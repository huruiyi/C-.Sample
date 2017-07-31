#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"LinkList.hpp"

//普通函数
void myPrint(int val)
{
	cout << val << " ";
}

//函数对象(仿函数)
struct hePrint
{
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	LinkList<int> list;
	list.pushBack(10);
	list.pushBack(20);
	list.pushBack(30);
	list.pushBack(40);
	list.pushBack(50);
	list.insert(2, 100);  //10 20 100 30 40 50

	//list.foreach(myPrint);
	list.foreach(hePrint());
	cout << endl;

	cout << "-----------" << endl;
	LinkList<int> newlist(list);
	newlist.foreach(hePrint());
	cout << endl;

	cout << "-----------" << endl;
	LinkList<int> templist;
	templist = newlist;
	templist.foreach(hePrint());
	cout << endl;

	cout << "删除100之后:" << endl;
	templist.remove(100);
	templist.foreach(hePrint());
	cout << endl;
	cout << "删除50之后:" << endl;
	templist.remove(50);
	templist.foreach(hePrint());
	cout << endl;
	cout << "在尾部添加200之后:" << endl;
	templist.pushBack(200);
	templist.foreach(hePrint());
	cout << endl;
}

void test02()
{
	LinkList<int> list;
	list.pushBack(10);
	list.pushBack(20);
	list.pushBack(30);
	list.pushBack(40);
	list.pushBack(50);

	//myPrint函数名就是指针

	hePrint he;
	he(20); //he.operator()(10);
	list.foreach(he);
}

class Person
{
public:
	Person()
	{
	}

	Person(const int & a)
	{
		this->mA = a;
	}
public:
	int mA;
};
void test03()
{
	LinkList<Person> list;
	list.pushBack(Person(1));
	list.pushBack(Person(2));
	list.pushBack(Person(3));
	list.pushBack(Person(4));
}

template <class T>
T func(T x, T y)
{
	return x + y;
}
int main() {
	//func(3, 5);
	//func<>(3, 5);
	//func(3, 2.5);
	//func<int>(3, 2.5);
	test03();

	test01();

	system("pause");
	return EXIT_SUCCESS;
}