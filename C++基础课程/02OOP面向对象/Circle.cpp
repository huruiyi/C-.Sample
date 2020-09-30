#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle() { std::cout << "构造函数执行中...\n"; }
Circle::~Circle() { std::cout << "析构函数执行中...\n"; }

void Circle::setHeart(int x, int y)
{
	mHeart.setX(x);
	mHeart.setY(y);
}
void Circle::setHeart(const Point_V1& point)
{
	mHeart.setX(point.getX());
	mHeart.setY(point.getY());
}
void Circle::setR(int r)
{
	if (r <= 0)
	{
		return;
	}
	mR = r;
}

int Circle::getR()
{
	return mR;
}
Point_V1 Circle::getHeart()
{
	return mHeart;
}
//判断点和圆的关系
void Circle::judgeCirleAndPointRelation(Point_V1& point)
{
	//using namespace std;
	//using std::pow;

	int x = mHeart.getX() - point.getX();
	int y = mHeart.getY() - point.getY();
	double distance = std::pow(x, 2) + std::pow(y, 2);

	double rd = std::pow(mR, 2);

	if (distance == rd)
	{
		std::cout << "点在圆上!" << std::endl;
	}
	else if (distance < rd)
	{
		std::cout << "点在圆内!" << std::endl;
	}
	else
	{
		std::cout << "点在圆外!" << std::endl;
	}
}