#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��C++��2����һ�������Ͳ��ܹ�ֱ�Ӹ�ֵ
class Base {};
class Derived : public Base {};

void test01()
{
	//�������Ĵ�С>=�����С��
	//����Ĵ�СӰ�����ָ���Ѱַ��Χ
	Base *b = new Derived;

	//Derived d;
	//Base b = d;

	//Base bb;
	//Derived dd = bb;
}

class Animal
{
public:
	virtual void Speak() = 0;
};

class Dog : public Animal
{
public:
	virtual void Speak()
	{
		cout << "Dog::Speak()" << endl;
	}
};

class Cat : public Animal
{
public:
	virtual void Speak()
	{
		cout << "Cat::Speak()" << endl;
	}
};

void doLogic(Animal &animal)
{
	//����������ָ��������õ������ڱ���׶�ȷ��Speak�����ĵ���
	//���ڵ��õ���Speak��Animal���Ͷ������Ա������ͽ��˺��������ڱ���׶ΰ�ΪAnimal��Speak����
	animal.Speak();

	cout << typeid(animal).name() << endl;
}

void test02()
{
	//Animal animal;
	//doLogic(animal);

	//���۴������Ǹ�������Ȼ���ø����Speak����
	//������Ҫ����ʲô���󣬾͵����Ǹ������Speak����
	//ԭ������Ϊ�˺��������õ��Ǿ�̬��
	//����취��Ҫ�ñ������ڱ���׶θ�����ȷ�������ĵ��ã������н׶θ���ָ�������������
	//ָ��Ķ�����ȷ����������
	Dog dog;
	doLogic(dog);

	cout << "---------" << endl;
	((void(*)())*((int *)*(int *)&dog + 0))();

	//dog.Animal::Speak();

	cout << "---------" << endl;

	Cat cat;
	doLogic(cat);

	//��̬ʵ������
	//����ָ���������ָ���������
	//�������麯��
	//������д������麯��
}

//���麯�����麯��һ������Ϊ��ʵ�ֶ�̬
//���麯��û��ʵ�֣�����Ϊ���û���ָ���������ָ��������󣬴Ӷ�ʵ�ֵ������ຯ��
//ֻҪ���а������麯�����������������࣬����಻�ܹ���ʵ����
//����̳��˳����࣬�������Ҫʵ�ָ������涨�����еĴ��麯��
int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}