#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person构造函数!" << endl;
		pName = (char *)malloc(64);
		strcpy(pName, "Hello world!");
	}

	void init()
	{
		cout << "Person初始化" << endl;
	}
	~Person()
	{
		cout << "Person析构函数!" << endl;
		if (pName != NULL)
		{
			free(pName);
		}
	}
public:
	char *pName;
};

void test()
{
	//C++创建对象 1.分配内存 2.初始化
	//释放对象 1. 清理工作 2.内存释放
	Person *person = (Person *)malloc(sizeof(Person));
	if (person == NULL)
	{
		return;
	}
	person->init();

	free(person);

	//在C++中动态创建对象不再使用malloc free,使用new delete运算符创建动态对象
}

//1. new和delete运算符的使用
void test02()
{
	//先分配内存，再调用构造函数
	Person *person = new Person;

	//先调用析构函数，再释放内存
	delete person;
}

//2. new和delete创建对象数组
void test03()
{
	//1. new创建基础数据类型数组
	int *pp = new int(10);
	int *p1 = new int[10];
	char *p2 = new char[64];
	char **p3 = new char*[10];

	//2. new创建自定义对象数组
	//new对象数组的时候，编译器需要调用对象的默认构造函数,所以必须提供默认构造函数
	Person *persons = new Person[10];
	delete[] persons;

	//如果new的时候加了[],那么delete时候一定要加上[]

	//delete void*不会调用对象的析构函数
	cout << "---------" << endl;
	void *ps = new Person;
	delete ps;
}
class Print
{
public:
	int pA;
	Print()
	{
		cout << "A" << endl;
	}
};
int main()
{
	Person a, b[2], *c;

	a.pName = "abc";
	b[0].pName = "abc";
	b[1].pName = "def";

	c = &a;
	c->pName = "def";
	system("pause");
	return EXIT_SUCCESS;
}