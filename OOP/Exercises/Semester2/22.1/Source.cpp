#include<string>
#include<iostream>
#include<myHeader.h>

using namespace std;


int main()
{
	double x,y;
	
	cout << "Seite a eingeben: ";
	cin >> x;
	
	cout << "Seite b eingeben: ";
	cin >> y;
	
	MyRectangle Rectangle = MyRectangle(x, y);
	
	Rectangle.calculateArea();
	
	cout << "Die Flaeche des Rechteckes lautet: " << Rectangle.getArea() << endl;
	
	system("PAUSE");
	return 0;
}