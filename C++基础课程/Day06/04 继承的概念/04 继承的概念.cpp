#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class CommonInfo
{
public:
	void Header()
	{
		cout << "�°�Ĺ���ͷ����Ϣ!" << endl;
	}

	void Footer()
	{
		cout << "�����ײ���Ϣ!" << endl;
	}

	void Left()
	{
		cout << "��������Ϣ!" << endl;
	}
};

class IndexPage : public CommonInfo
{
public:
	void MainBody()
	{
		cout << "��ҳ���岿��!" << endl;
	}
};

class NewsPage : public CommonInfo
{
public:
	void MainBody()
	{
		cout << "����ҳ����!" << endl;
	}
};

void test()
{
	IndexPage ip;
	ip.Header();
	ip.Left();
	ip.MainBody();
	ip.Footer();

	cout << "---------" << endl;

	NewsPage np;
	np.Header();
	np.Left();
	np.MainBody();
	np.Footer();
}

//1. �̳о����������ô���
//2. �����е�����й�����չ
//3. �̳е�����Ŀ����Ϊ��ʵ�ֶ�̬

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}