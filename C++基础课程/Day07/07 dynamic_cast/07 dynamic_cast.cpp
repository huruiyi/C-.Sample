#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void func() {    }
};
class Dog : public Animal
{
public:
	virtual void func() {    }
};

//ֻ�����ھ��м̳й�ϵ��ָ��������ã�ֻ����������ת��(����Ƕ�̬�Ļ�����������)
void test()
{
	//1. û�з�����̬��ʱ��
	Animal *animal = new Animal;
	Dog *d = dynamic_cast<Dog *>(animal);

	Dog *dog = new Dog;
	Animal *a = dynamic_cast<Animal *>(dog);

	//2. ������̬
	Animal *aa = new Dog;
	Dog *dd = dynamic_cast<Dog *>(aa);
	dynamic_cast<Animal *>(dd);
}

int main() {
	test();
	system("pause");
	return EXIT_SUCCESS;
}