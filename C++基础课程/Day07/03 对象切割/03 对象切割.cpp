#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void Speak()
	{
		cout << "Animal::Speak()" << endl;
	}
};

class Dog : public Animal
{
public:
	virtual void Speak()
	{
		cout << "Dog::Speak()" << endl;
	}
};

void test()
{
	//����ָ���������ָ���������
	Dog dog;
	//�����������ת���ɸ�����󣬷����˶����и�
	//�����и�����������ĳ�Աȫ���޳���
	Animal animal = dog;
	animal.Speak();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}