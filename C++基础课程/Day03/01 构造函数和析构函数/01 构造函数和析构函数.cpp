#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//����ĳ�ʼ����������ĳ�Ա��������ʼֵ
//��ʼ����Ŀ����Ϊ�˼��ٲ���Ҫ�ĳ�������
//ע�⣺�Ժ����κεı�����Ҫ����ʼ��

class Person
{
public:
	//������������һ��
	//û�з���ֵ������дvoid
	//���캯�������в���
	//���캯����������
	//���캯���ڴ��������ʱ���Զ�����
	//���캯��ֻ�ᱻ����һ��,�ڶ�����޵��д�����ʱ��
	//ֻҪ���캯�����ã��ض������һ���µĶ���
	//�޲ι��캯��(Ĭ�Ϲ��캯��)
	Person()
	{
		cout << "Person���캯��!" << endl;
		mA = 0;
		mB = 0;
	}

	//�������� ~����
	//���������ڶ����ڴ���������֮ǰ����
	//��������Ҳ�Ǳ��Զ����õ�
	//�������������в���
	//�����������ܹ�������
	~Person()
	{
		cout << "Person��������������" << endl;
	}

	//һ������£����ü��ι��캯���ͻ���ü�����������
	//���캯������������������ֶ���ӣ�������������һ��Ĭ�ϵĹ��캯�� һ��Ĭ�ϵ���������
	//Ĭ�ϵ������͹��죬Ĭ��ʲô������

public:
	int mA;
	int mB;
};

void test()
{
	Person person;
}

//һ������£�ֻҪ����ڲ���ָ�룬����ָ��ָ���˶��ڴ棬������������Ҫд
class Student
{
public:
	Student(const char *name, int age)
	{
		cout << "Student���캯��!" << endl;
		pName = (char *)malloc(sizeof(char)* strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}

	void printPerson()
	{
		cout << "Name:" << pName << " Age:" << mAge << endl;
	}

	~Student()
	{
		if (pName != NULL)
		{
			cout << "Student��������������" << endl;
			free(pName);
			pName = NULL;
		}
	}

public:
	char *pName;
	int mAge;
};

void test02()
{
	Student s("Trump", 88);
	s.printPerson();
}

int main() {
	//test();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}