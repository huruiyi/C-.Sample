#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ʵ���� Person p;
//��̬��Ա��������Person�����Ķ�����

class Person
{
public:
	static int getNum()
	{
		return mNum;
	}
private:
	//��̬��Ա����
	static int mNum;  //������������д��뵱����̬����������
	int mAge;
};

int Person::mNum = 100; //�����ʼ�������ⶨ��

void test01()
{
	//1. ֱ��ͨ������������
	cout << Person::getNum() << endl;

	//2. ͨ������������
	Person p1, p2, p3;

	//p2.mNum = 200;

	cout << p1.getNum() << endl;
	cout << p2.getNum() << endl;
	cout << p3.getNum() << endl;

	//3. ��̬��ԱҲ�з���Ȩ��
}

//��̬��Ա����Ŀ����Ϊ�˹�������
//��̬��Ա����Ŀ����Ϊ�˷��ʾ�̬��Ա����

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}