#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>

class MyString
{
	//����ַ���
	friend std::ostream& operator<<(std::ostream &out, const MyString &str);
	//�����ַ���
	friend std::istream& operator>>(std::istream &in, MyString &str);

public:
	MyString();
	MyString(const char *s);
	MyString(int n, char ch);
	MyString(const MyString &str);
	~MyString();
	MyString& operator=(const MyString &str);

	//�ַ���ȡ
	char& operator[](int index);
	//�ַ���ƴ�Ӳ���
	MyString operator+(const MyString &str);
	MyString operator+(const char *s);
	//�ַ���׷�Ӳ���
	MyString& operator+=(const MyString &str);
	MyString& operator+=(const char *s);
	//�Ƚϲ���
	bool operator==(const MyString &str);
	bool operator==(const char *s);
	//��С����
	int size();
	//MyString -> const char *
	const char* c_str();

private:
	char *pString; //ָ�������洢�ַ����Ŀռ�
	int mSize;
};