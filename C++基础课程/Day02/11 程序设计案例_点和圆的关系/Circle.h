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
	//�жϵ��Բ�Ĺ�ϵ
	void judgeCirleAndPointRelation(Point &point);
private:
	//Բ��
	Point mHeart;
	//�뾶
	int mR;
};