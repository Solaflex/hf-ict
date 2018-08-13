#include "myHeader.h"

Auto::Auto()
{
}
Auto::Auto(int x)
{
	_a = x;
}

void Auto::setValue(int x)
{
	_a = x;
}

void Auto::showValue()
{
	cout << _a << endl;
}
