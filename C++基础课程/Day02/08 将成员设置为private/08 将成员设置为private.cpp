#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void setReadWrite(string param)
	{
		mReadWrite = param;
	}

	string getReadWrite()
	{
		return mReadWrite;
	}

	string getOnlyRead()
	{
		return mOnlyRead;
	}

	void setOnlyWrite(string param)
	{
		mOnlyWtite = param;
	}

private:
	string mReadWrite;
	string mOnlyRead;
	string mOnlyWtite;
};

//���Կ��Ƴ�Ա�Ķ�д����Ȩ��
//�Գ�Ա�ĸ�ֵ������Ч��У��

int main() {
	system("pause");
	return EXIT_SUCCESS;
}