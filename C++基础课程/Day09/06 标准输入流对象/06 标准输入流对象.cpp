#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
*/

void test00()
{
	char ch;
	cin.get(ch);
	cout << "ch = " << ch << endl;
	cin.get(ch);
	cout << "ch = " << ch << endl;
	ch = cin.get();
	if (ch == '\n')
	{
		cout << "���һ���ַ��ǻ��У�" << endl;
	}
}
void test01()
{
	char buf[5] = { 0 };
	cin.get(buf, 5);//�������5���ַ����ܣ����ᱨ�쳣
	cout << buf;

	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "���һ���ַ��ǻ��У�" << endl;
	}

	//cin.get��ȡһ�����ݣ����ǲ����߻��У������ַ���Ȼ���ڻ�����
}
/*
cin.getline()
*/

void test02()
{
	char buf[5] = { 0 };
	cin.getline(buf, 7);//���ܴ��ڻ�������С
	cout << buf << endl;

	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "���һ���ַ��ǻ��У�" << endl;
	}

	//cin.getline��ȡһ�����ݣ������ӵ������ַ�
}

/*
cin.ignore()
cin.peek()
cin.putback()
*/

void test03()
{
	//���Ե�ǰ�ַ����ӵ���ǰ�ַ� asd
	cin.ignore(2);
	//����ǰ�����ַ�
	char ch = cin.get();
	cout << "ch = " << ch << endl;
}

void test04()
{
	//͵�������µ�ǰ�ַ���ʲô�����ǲ�ȡ������ asd
	char ch = cin.peek();
	cout << "ch = " << ch << endl;
	ch = cin.get();
	cout << "ch = " << ch << endl;
}

void  test05()
{
	char ch = cin.get();
	//��ch�ַ��ٷŻػ�������ǰλ�� asd

	cout << ch << endl;
	cin.putback(ch);
	cout << ch << endl;

	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	cout << buf << endl;
}
int main()
{
	test05();

	system("pause");
	return EXIT_SUCCESS;
}