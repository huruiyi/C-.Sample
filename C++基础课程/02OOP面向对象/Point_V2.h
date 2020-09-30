#pragma once
class Point_V2
{
	void setPoint(int x, int y);
	void printPoint();
	virtual void printInfo();

	~Point_V2();
private:
	int xPos = 0;
	int yPos = 0;
};

