#include<iostream>
#include<string>
#include<myHeader.h>

using namespace std;


int main()
{
	double dx(0), dy(0), axValue(2);
	Point p1(0,0);
	cout << "x und y Werte eingeben:" << endl;
	cin >> dx; cin >> dy;
	p1.setPoint(dx, dy);
	

	cout << "Die Achse um " << axValue << " verschieben" << endl;
	p1.shiftAxis(axValue);

	cout << "Position von p1: x=" << p1.getX() << " y=" << p1.getY() << endl;
	Point p2(p1);
		
	cout << "Position von p2: " << endl;
	p2.showPoint();
	
	system("PAUSE");
	return 0;
}