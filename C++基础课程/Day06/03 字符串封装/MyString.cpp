#include "MyString.h"

MyString::MyString()
{
	this->pString = NULL;
	this->mSize = 0;
}

MyString::MyString(const char* s)
{
	this->pString = new char[strlen(s) + 1];
	strcpy(this->pString, s);
	this->mSize = strlen(s);
}

MyString::MyString(int n, char ch)
{
	this->mSize = n;
	this->pString = new char[this->mSize + 1];
	memset(pString, 0, this->mSize + 1);
	for (int i = 0; i < n; ++i)
	{
		this->pString[i] = ch;
	}
}

MyString::MyString(const MyString& str)
{
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->mSize = str.mSize;
}

MyString& MyString::operator=(const MyString& str)
{
	//���ͷ��ڴ�
	if (pString != NULL)
	{
		delete[] this->pString;
		pString = NULL;
	}

	//�ٿ�������
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->mSize = str.mSize;

	return *this;
}

//�ַ���ȡ
char& MyString::operator[](int index)
{
	return this->pString[index];
}

//�ַ���ƴ�Ӳ���  mystring str1 + str2
MyString MyString::operator+(const MyString& str)
{
	if (NULL == str.pString)
	{
		return *this;
	}

	int size = this->mSize + str.mSize;
	char* newspace = new char[size + 1];
	memset(newspace, 0, size + 1);

	//strcat
	strcat(newspace, this->pString);
	strcat(newspace, str.pString);

	MyString temp;
	temp.pString = newspace;
	temp.mSize = size;

	return temp;
}

MyString MyString::operator+(const char* s)
{
	if (NULL == s)
	{
		return *this;
	}

	int size = this->mSize + strlen(s);
	char* newspace = new char[size + 1];
	memset(newspace, 0, size + 1);

	//strcat
	strcat(newspace, this->pString);
	strcat(newspace, s);

	MyString temp;
	temp.pString = newspace;
	temp.mSize = size;

	return temp;
}

//�ַ���׷�Ӳ���  MyString s = "aaa";  s += "ssssss";
MyString& MyString::operator+=(const MyString & str)
{
	if (NULL == str.pString)
	{
		return *this;
	}

	int size = this->mSize + str.mSize;
	char* newspace = new char[size + 1];
	memset(newspace, 0, size + 1);

	strcat(newspace, this->pString);
	strcat(newspace, str.pString);

	//�ͷŵ�ǰ�ַ�ԭ�еĿռ�
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = newspace;
	this->mSize = size;

	return *this;
}

MyString& MyString::operator+=(const char* s)
{
	if (NULL == s)
	{
		*this;
	}

	int size = this->mSize + strlen(s);
	char* newspace = new char[size + 1];
	memset(newspace, 0, size + 1);

	strcat(newspace, this->pString);
	strcat(newspace, s);

	//�ͷŵ�ǰ�ַ�ԭ�еĿռ�
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = newspace;
	this->mSize = size;

	return *this;
}

//�Ƚϲ���
bool MyString::operator==(const MyString & str)
{
	if (NULL == str.pString)
	{
		return false;
	}

	if (this->mSize != str.mSize)
	{
		return false;
	}

	if (strcmp(this->pString, str.pString) != 0)
	{
		return false;
	}

	return true;
}

bool MyString::operator==(const char* s)
{
	if (NULL == s)
	{
		return false;
	}

	if (this->mSize != strlen(s))
	{
		return false;
	}

	if (strcmp(this->pString, s) != 0)
	{
		return false;
	}

	return true;
}

//��С����
int MyString::size()
{
	return this->mSize;
}

//MyString -> const char *
const char* MyString::c_str()
{
	return this->pString;
}

//����
MyString::~MyString()
{
	if (pString != NULL)
	{
		delete[] this->pString;
		pString = NULL;
	}
}

//����ַ���
std::ostream& operator<<(std::ostream & out, const MyString & str)
{
	out << str.pString;
	return out;
}

//�����ַ��� MyString str; cin >> str;
std::istream& operator>>(std::istream & in, MyString & str)
{
	char buf[1024] = { 0 };
	in.getline(buf, 1024);

	//���ж��ַ����Ƿ��ſռ�
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
		str.mSize = 0;
	}

	str.pString = new char[strlen(buf) + 1];
	strcpy(str.pString, buf);
	str.mSize = strlen(buf);

	return in;
}