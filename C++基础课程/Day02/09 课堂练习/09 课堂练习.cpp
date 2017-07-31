#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//��������û�н��г�ʼ�����ǳ����зǳ��ձ������
class Person
{
public:
	void init()
	{
		mName = "undefined";
		mAge = 0;
	}

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

	void printPerson()
	{
		cout << "Name:" << mName << " Age:" << mAge << endl;
	}

private:
	string mName;
	int mAge;
};

int main() {
	Person person;
	//��ʼ��
	person.init();
	person.printPerson();
	person.setName("Obama");
	person.setAge(101);
	person.printPerson();

	system("pause");
	return EXIT_SUCCESS;
}