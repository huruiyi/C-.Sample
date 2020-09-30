#include "Point_V2.h"
#include <iostream>

using namespace std;

void Point_V2::printPoint() {
	cout << "[" << this->xPos << "," << this->yPos << "]" << endl;
}

void Point_V2::setPoint(int x, int y) {
	this->xPos = x;
	this->yPos = y;
}

void Point_V2::printInfo()
{
	cout << "printInfo..........." << endl;
}

Point_V2::~Point_V2() {
	std::cout << this->xPos << "," << this->yPos << "=Îö¹¹º¯Êý" << endl;
}