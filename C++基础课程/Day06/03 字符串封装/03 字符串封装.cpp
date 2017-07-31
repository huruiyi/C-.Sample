#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyString.h"

void test()
{
	MyString s1 = "aaa";
	MyString s2 = "bbb";
	MyString s3 = s1 + s2;
	s1 += s2;

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;

	//cin标准输入流对象
	cout << "-----------" << endl;
	cin >> s1;
	cout << "s1:" << s1 << endl;

	s1 += " hello world!";
	cout << "s1:" << s1 << endl;
	MyString s4 = s1 + " ppppp";
	cout << "s4:" << s4 << endl;

	if (s1 == "hello world")
	{
		cout << "相等!" << endl;
	}
	else
	{
		cout << "不相等!" << endl;
	}

	for (int i = 0; i < s4.size(); ++i)
	{
		cout << s4[i] << " ";
	}
	cout << endl;
}

void test2()
{
	//MyString::MyString(const char *s)
	MyString s1("ABCDE");

	//MyString::MyString(int n, char ch)
	MyString s2(10, 'A');
#if 0

	//MyString::MyString(const MyString &str)
	MyString s3 = s1;
	MyString s4(s2);

	//MyString& MyString::operator=(const MyString &str)
	s1 = s2;

	//char& MyString::operator[](int index)
	s1[0];

	//MyString MyString::operator+(const MyString &str)
	MyString  s3 = s1 + s2;

	//MyString MyString::operator+(const char *s)
	MyString s4 = s1 + "FGHIJK";

	//MyString& MyString::operator+=(const MyString &str)
	s1 += s2;
	cout << s1 << endl;
	//MyString& MyString::operator+=(const char *s)
	s1 += "FGHIJ";
	cout << s1 << endl;
#endif
	//bool MyString::operator==(const MyString &str)
	cout << (s1 == s2 ? "相等" : "不相等") << endl;

	//bool MyString::operator==(const char *s)
	cout << (s1 == "ABCDE" ? "相等" : "不相等") << endl;

	//????????????????????????????????????????????
	//cout << ("ABCDE" == s1 ? "相等" : "不相等") << endl;

	//int MyString::size()
	cout << s1.size() << endl;

	//const char* MyString::c_str()
	const  char* p = s1.c_str();
}
int main()
{
	test2();
	system("pause");
	return EXIT_SUCCESS;
}