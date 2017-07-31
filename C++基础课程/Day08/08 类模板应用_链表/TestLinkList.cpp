#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"LinkList.hpp"

//��ͨ����
void myPrint(int val)
{
	cout << val << " ";
}

//��������(�º���)
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

	cout << "ɾ��100֮��:" << endl;
	templist.remove(100);
	templist.foreach(hePrint());
	cout << endl;
	cout << "ɾ��50֮��:" << endl;
	templist.remove(50);
	templist.foreach(hePrint());
	cout << endl;
	cout << "��β�����200֮��:" << endl;
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

	//myPrint����������ָ��

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