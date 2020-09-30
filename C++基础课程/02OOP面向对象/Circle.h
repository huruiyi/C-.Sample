#pragma once
#include"Point_V1.h"

class Circle
{
public:
	Circle();
	~Circle();

	void setHeart(int x, int y);
	void setHeart(const Point_V1& point);

	void setR(int r);
	int getR();

	Point_V1 getHeart();
	//判断点和圆的关系
	void judgeCirleAndPointRelation(Point_V1& point);
private:
	//圆心
	Point_V1 mHeart;
	//半径
	int mR;
};