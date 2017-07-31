#pragma once
#include"Point.h"

class Circle
{
public:
	void setHeart(int x, int y);
	void setHeart(const Point &point);
	void setR(int r);
	int getR();
	Point getHeart();
	//判断点和圆的关系
	void judgeCirleAndPointRelation(Point &point);
private:
	//圆心
	Point mHeart;
	//半径
	int mR;
};