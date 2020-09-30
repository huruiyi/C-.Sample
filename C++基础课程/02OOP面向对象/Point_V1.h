#pragma once
class Point_V1
{
public:
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
private:
	int mX = 0;
	int mY = 0;
};
