#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cout.flush() //ˢ�»�����
cout.put() //�򻺳���д�ַ�
cout.write() //��buffe��дnum���ֽڵ���ǰ������С�
*/

void test01()
{
	//��������ַ�
	cout.put('a').put('b').put('\n');
	cout.write("hello", 6).write("world", 6);

	cout << "************" << endl;
	//����ַ���
	char buf[] = "hello world!";
	cout.write(buf, strlen(buf));

	cout << endl;
	cout << "***************************************" << endl;
	int len = strlen(buf);
	for (int i = 0; i < len; i++)
	{
		cout << i << "��";
		cout.write(buf, i);
		cout << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}