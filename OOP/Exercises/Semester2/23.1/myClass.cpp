#include<iostream>
#include<string>
#include<myHeader.h>

using namespace std;

Point::Point(double x, double y)
{
	this->_x = x;
	this->_y = y;	
}

Point::Point(const Point &P)
{
	this->_x = P._x;
	this->_y = P._y;	
}

void Point::setPoint(double x, double y)
{
	this->_x = x;
	this->_y = y;
}

void Point::showPoint()
{
	cout << "X: " << this->_x << " - Y: " << this->_y << endl;
}

double Point::getX() const
{
	return this->_x;
}

double Point::getY() const
{
	return this->_y;
}

void Point::shiftAxis(double value)
{
	this->_x -= value;
	this->_y -= value;
}

