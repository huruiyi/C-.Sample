#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//Ϊʲôʹ�ú꺯��?�꺯����ʲô�ô�?
//

int func(int a, int b)
{
	return a + b;
}

#define MyFunc(a, b) ((a) + (b))

//���ڶ�С����Ƶ��ʹ�õĺ�����һ���д�ƺ꺯��

int main() {
	func(10, 20);

	int a = MyFunc(10, 20);
	cout << a << endl;

	double d = MyFunc(1.8, 2.2);
	cout << d << endl;

	system("pause");
	return EXIT_SUCCESS;
}