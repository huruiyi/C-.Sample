#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int mA)
	{
		this->mA = mA;
		mB = 100;
	}

	void printPerson() const
	{
	}

	//��������const���ε��ǳ�Ա������thisָ��
	//��ʾ�����ڲ�����ͨ��thisָ���޸�thisָ��ָ��ռ��ֵ
	//���˵������mutable���εģ���ô���ܳ���������
	void showPerson() const
	{
		if (this == NULL)
		{
			return;
		}
		cout << "hello world:" << this->mA << endl;

		//this->mA = 100;
		//this = NULL;
		//const Person *const this;

		this->mB = 200;
	}

public:
	int mA;
	mutable int mB;
};

//��ĳ�Ա�����ڲ���this�ɼ�Ҳ�ɲ���
//����βα������ͳ�Ա��������ͻ������this����

void test()
{
	Person* person = new Person(10);
	person->showPerson();
	//showPerson(person);

	delete person;
}

//��������
void test02()
{
	const Person person(10);

	//��������Է��ʳ�Ա���������ǲ����޸ĳ�Ա����������mutable���εĳ�Ա����
	//������ֻ�ܵ��ó�����
	//���������const���Σ���ʾ���󲻻��޸ģ�����ֻ�ܵ�����const���εĳ�Ա����

	person.printPerson();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}