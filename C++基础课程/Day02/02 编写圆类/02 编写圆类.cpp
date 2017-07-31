#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Circle
{
public:
	//赋值函数 成员函数 成员方法
	//在类的内部，成员函数可以直接访问类的成员变量
	void setR(int r)
	{
		if (r <= 0)
		{
			return;
		}
		mR = r;
	}
	int getZhouLength()
	{
		return (int)(2 * mR *3.14);
	}
public:
	//半径
	int mR; //成员变量 成员属性
};

void test()
{
	Circle c;
	c.setR(10);
	cout << "周长是:" << c.getZhouLength() << endl;
}

//1. 类具有那些属性(只定义业务中需要的属性)
//2. 针对这些属性的操作(函数)

class Student
{
public:
	void setName(string name)
	{
		mName = name;
	}
	void setAge(int age)
	{
		if (age < 0 || age > 100)
		{
			return;
		}

		mAge = age;
	}

	void printStudent()
	{
		cout << "Name:" << mName << " Age:" << mAge << endl;
	}
public:
	string mName;
	int mAge;
};

void test02()
{
	Student s;
	s.setName("aaa");
	s.setAge(10);
	s.printStudent();
}

//内联函数不一定进行内联编译
//内联函数只有进行内联编译才会替换到函数调用的地方，才会省去函数调用开销
//inline关键字建议编译给我们内联编译，但是编译器拒绝请求
//有些比较好的编译器，即使我们不写inline关键字，也会帮我们优化程序，对函数进行内联编译

int main() {
	//test();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}