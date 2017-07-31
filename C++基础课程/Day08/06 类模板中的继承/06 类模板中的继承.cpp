#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class Animal
{
public:
	T mA;
};

//1. 普通类继承类模板
class Dog : public Animal<int>
{
public:
	int mB;
};

//2. 类模板继承类模板
template<class T, class T2>
class Cat : public Animal<T2>
{
public:
	Cat()
	{
	}
public:
	T mC;
};

int main() {
	Cat<int, int> c;

	system("pause");
	return EXIT_SUCCESS;
}