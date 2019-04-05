#pragma once

class Cube
{
public:
	void setL(int l);

	void setW(int w);

	void setH(int h);

	//告诉编译器，放心吧，我不会修改成员变量的值
	//常函数
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