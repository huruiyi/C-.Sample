#pragma once

class Cube
{
public:
	void setL(int l);

	void setW(int w);

	void setH(int h);

	//���߱����������İɣ��Ҳ����޸ĳ�Ա������ֵ
	//������
	int getL() const;

	int getW() const;

	int getH() const;

	int caculateS();

	int caculateV();

	bool CubeComapreCube(const Cube& c);

private:
	int mL;
	int mW;
	int mH;
};