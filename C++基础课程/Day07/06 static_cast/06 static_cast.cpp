#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal {};
class Dog : public Animal {};
class Other {};

void test()
{
	//1. �Ի����������ͽ�������ת��
	double a = 3.14;
	int b = static_cast<int>(a);

	//2. �Ծ��м̳й�ϵ��ָ���������֮���������ת
	Animal* animal = new Animal;
	Dog* dog = static_cast<Dog*>(animal); //����ȫ

	Dog* d = new Dog;
	Animal* aa = static_cast<Animal*>(d); //��ȫ

	//Other *o = static_cast<Other *>(animal);
}

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}