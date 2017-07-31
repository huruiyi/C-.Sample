#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal ���캯��!" << endl;
		pName = new char[64];
	}

	virtual void func()
	{
		cout << "Animal::func()" << endl;
	}

#if 0
	virtual ~Animal()
	{
		cout << "Animal ��������!" << endl;
	}
#endif

	//����������������������Ȼ���������࣬���ܱ�ʵ����
	//����������������������ʵ��
	virtual ~Animal() = 0;
public:
	char *pName;
};

Animal::~Animal()
{
}

class Dog : public Animal
{
public:
	Dog()
	{
		cout << "Dog ���캯��!" << endl;
		pName = new char[64];
	}

	virtual void func()
	{
		cout << "Dog::func()" << endl;
	}

	~Dog()
	{
		cout << "Dog ��������!" << endl;
		if (pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}
	}
public:
	char *pName;
};

void test()
{
	Animal *animal = new Dog;
	animal->func();

	delete animal;

	//��������̬��ʱ������ͨ������ָ��ȥ�ͷ���������ʱ��������󲻻������������
	//������������������ڶ�̬������£�ͨ������ָ�����ͷ��������
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}