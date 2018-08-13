// Prüfung_Vererbung
#include <C:\git\RunProject\RunProject\myHeader.h>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Container { // ABSTRAKTE BASISKLASSE
public:
	Container() { cout << "Container created" << endl; }
	virtual ~Container() { cout << "Container destroyed" << endl; }
	virtual void add(int value) = 0; // pure virtual function
	void xy() { cout << "xy" << endl; }
};

class LinkedList : public Container {
public:
	LinkedList() { cout << "LinkedList created" << endl; }
	~LinkedList() { cout << "LinkedList destroyed" << endl; }
	void add(int value) { cout << "LinkedList::add" << endl; }
};

class Array : public Container {
public:
	Array() { cout << "Array created" << endl; }
	~Array() { cout << "Array destroyed" << endl; }

};

class XYZ : public Array {
public:
	void add(int value) { cout << "add" << endl; }
};

int main()
{

	Container *obj;
	obj = new XYZ();
	obj->xy();
	

	system("PAUSE");

	return 0;

}



