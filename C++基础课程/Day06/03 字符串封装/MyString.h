#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>

class MyString
{
	//输出字符串
	friend std::ostream& operator<<(std::ostream &out, const MyString &str);
	//输入字符串
	friend std::istream& operator>>(std::istream &in, MyString &str);

public:
	MyString();
	MyString(const char *s);
	MyString(int n, char ch);
	MyString(const MyString &str);
	~MyString();
	MyString& operator=(const MyString &str);

	//字符存取
	char& operator[](int index);
	//字符串拼接操作
	MyString operator+(const MyString &str);
	MyString operator+(const char *s);
	//字符串追加操作
	MyString& operator+=(const MyString &str);
	MyString& operator+=(const char *s);
	//比较操作
	bool operator==(const MyString &str);
	bool operator==(const char *s);
	//大小操作
	int size();
	//MyString -> const char *
	const char* c_str();

private:
	char *pString; //指向真正存储字符串的空间
	int mSize;
};