#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Cube.h"
using namespace std;

bool CubeComapreCube(const Cube& c1, const Cube& c2)
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}

	return false;
}

void test()
{
	Cube c1;
	c1.setH(10);
	c1.setL(20);
	c1.setW(30);

	Cube c2;
	c2.setH(20);
	c2.setL(20);
	c2.setW(30);

	cout << "c1�����:" << c1.caculateS() << endl;
	cout << "c1�����:" << c1.caculateV() << endl;
	cout << "c2�����:" << c2.caculateS() << endl;
	cout << "c2�����:" << c2.caculateV() << endl;

	//1. ȫ�ֺ����ķ�ʽ�Ƚ�
	if (CubeComapreCube(c1, c2))
	{
		cout << "���!" << endl;
	}
	else
	{
		cout << "�����!" << endl;
	}

	//2. ��Ա������ʽ
	if (c1.CubeComapreCube(c2))
	{
		cout << "���!" << endl;
	}
	else
	{
		cout << "�����!" << endl;
	}
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}