#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person;

class GirlFriend
{
public:
	void talk(Person& person);

	void beat(Person& person);
};

class Person
{
	friend void GirlFriend::beat(Person& person);
private:
	string mName;
};

void GirlFriend::talk(Person& person)
{
}

void GirlFriend::beat(Person& person)
{
	person.mName;
}

//������ʹ����ĳ�Ա��ʱ�򣬱����������ȿ�����Ľṹ
//���������ֻ���������������ǿ��Զ���һ�����û���ָ��

int main() {
	system("pause");
	return EXIT_SUCCESS;
}