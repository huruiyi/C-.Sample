#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include"Circle.h"
#include"Point.h"

//1. 需要两个类  点类  圆类

void test()
{
	Circle circle;
	circle.setHeart(10, 20);
	circle.setR(100);

	Point point;
	point.setX(200);
	point.setY(200);

	circle.judgeCirleAndPointRelation(point);
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}