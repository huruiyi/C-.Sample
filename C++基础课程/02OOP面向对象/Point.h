#pragma once

class Point
{
public:
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
private:
	int mX;
	int mY;
};