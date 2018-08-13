// Prüfung_Template
#include <C:\git\RunProject\RunProject\myHeader.h>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

template <class T>
class Container {
private:
	T value;
public:
	T getValue();
	void setValue(T value);
};

template <class T>
T Container<T>::getValue() {
	return value;
}

template <class T>
void Container<T>::setValue(T value) {
	this->value = value;
}

int main()
{

	// use class for type double
	Container<double> obj;
	double x = 3.1;

	obj.setValue(x);
	

	system("PAUSE");

	return 0;

}



