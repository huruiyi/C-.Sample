#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//��̬��Ա�ͷǾ�̬��Ա������������
	//�Ǿ�̬��Ա������thisָ��
	//��̬��Ա����û��thisָ��
	void showPerson()
	{
		cout << this->mAge << endl;
	}

	//��̬��Ա��������ʹ�÷Ǿ�̬��Ա����
	static void printPerson()
	{
		//mAge;
	}
public:
	int mAge;
};

#if 0
struct Person
{
	int mAge;
};

void showPerson(Person *this)
{
	cout << this->mAge << endl;
}
#endif

//��̬��Ա�ͷǾ�̬��Ա��������ռ�ö����С
//��̬��Ա����Ҳ��ռ�ö����С
void test01()
{
	Person p1, p2; // struct Person p1,p2;
	p1.mAge;
	p2.mAge;

	p1.showPerson(); //showPerson(&p1);
	p2.showPerson(); //showPerson(&p2);

	cout << sizeof Person << endl;
}

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}