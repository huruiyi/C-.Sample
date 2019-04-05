#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal {};
class Dog : public Animal {};
class Other {};

void test()
{
	//1. 对基本数据类型进行类型转换
	double a = 3.14;
	int b = static_cast<int>(a);

	//2. 对具有继承关系的指针或者引用之间进行类型转
	Animal* animal = new Animal;
	Dog* dog = static_cast<Dog*>(animal); //不安全

	Dog* d = new Dog;
	Animal* aa = static_cast<Animal*>(d); //安全

	//Other *o = static_cast<Other *>(animal);
}

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}