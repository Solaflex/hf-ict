#include<iostream>
#include<string>
#include<myHeader.h>

using namespace std;

MyRectangle::MyRectangle(double x, double y)
{
	this->_a = x;
	this->_b = y;
	this->_area = 0;
}

void MyRectangle::calculateArea()
{
	this->_area = this->_a * this->_b;	
}


double MyRectangle::getArea()
{
	return this->_area;
	
}