#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric> //accumulate ͷ�ļ�
#include <iterator>

void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int sum = accumulate(v.begin(), v.end(), 1000); //����3 ��ʼֵ

	cout << "0~100�ܺ�Ϊ�� " << sum << endl;
}

/*
fill�㷨 �����������Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value t���Ԫ��
*/
void test02()
{
	vector<int>v;

	v.resize(10);

	fill(v.begin(), v.end(), 100);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void test03()
{
	vector<int>v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(30);

	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int v){cout << v << " "; });

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
}

class myReplace
{
public:
	bool operator()(int v)
	{
		return v > 4;
	}
};

void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	replace(v.begin(), v.end(), 4, 400);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	replace_if(v.begin(), v.end(), myReplace(), 4000);
	replace_if(v.begin(), v.end(), myReplace(), [](int a) {return a > 5; });
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2;
	v2.push_back(10);
	v2.push_back(30);
	v2.push_back(20);

	swap(v, v2);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}