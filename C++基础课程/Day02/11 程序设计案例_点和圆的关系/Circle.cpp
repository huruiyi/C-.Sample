#include "Circle.h"
#include <cmath>
#include <iostream>

void Circle::setHeart(int x, int y)
{
	mHeart.setX(x);
	mHeart.setY(y);
}
void Circle::setHeart(const Point& point)
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
Point Circle::getHeart()
{
	return mHeart;
}
//判断点和圆的关系
void Circle::judgeCirleAndPointRelation(Point& point)
{
	//using namespace std;
	//using std::pow;

	double distance = std::pow(mHeart.getX() - point.getX(), 2) + std::pow(mHeart.getY() - point.getY(), 2);
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