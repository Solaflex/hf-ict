#include<myHeader.h>
#include<iostream>


using namespace std;

void myClass::setValue(int x)
{
	this->_a = x;
	
}

void myClass::showValue()
{
	cout << this->_a << endl;
}