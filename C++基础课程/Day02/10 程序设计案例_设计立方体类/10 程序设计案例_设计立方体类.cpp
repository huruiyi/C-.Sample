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

	cout << "c1面积是:" << c1.caculateS() << endl;
	cout << "c1体积是:" << c1.caculateV() << endl;
	cout << "c2面积是:" << c2.caculateS() << endl;
	cout << "c2体积是:" << c2.caculateV() << endl;

	//1. 全局函数的方式比较
	if (CubeComapreCube(c1, c2))
	{
		cout << "相等!" << endl;
	}
	else
	{
		cout << "不相等!" << endl;
	}

	//2. 成员函数方式
	if (c1.CubeComapreCube(c2))
	{
		cout << "相等!" << endl;
	}
	else
	{
		cout << "不相等!" << endl;
	}
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}