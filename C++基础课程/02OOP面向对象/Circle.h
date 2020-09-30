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
	//�жϵ��Բ�Ĺ�ϵ
	void judgeCirleAndPointRelation(Point_V1& point);
private:
	//Բ��
	Point_V1 mHeart;
	//�뾶
	int mR;
};