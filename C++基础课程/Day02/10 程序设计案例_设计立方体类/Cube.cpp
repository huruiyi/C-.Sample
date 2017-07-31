#include "Cube.h"

void Cube::setL(int l)
{
	mL = l;
}

void Cube::setW(int w)
{
	mW = w;
}

void Cube::setH(int h)
{
	mH = h;
}

//���߱����������İɣ��Ҳ����޸ĳ�Ա������ֵ
//������
int Cube::getL() const
{
	return mL;
}

int Cube::getW() const
{
	return mW;
}

int Cube::getH() const
{
	return mH;
}

int Cube::caculateS()
{
	return (mL * mH + mL * mW + mH *mW) * 2;
}

int Cube::caculateV()
{
	return mL * mW * mH;
}

bool Cube::CubeComapreCube(const Cube &c)
{
	if (getH() == c.getH() && getL() == c.getL() && getW() == c.getW())
	{
		return true;
	}

	return false;
}