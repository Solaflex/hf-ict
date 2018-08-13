// Prüfung_LinkedList

#include <iostream>
#include <string>
#include <vector>
#include <C:\git\RunProject\RunProject\myHeader.h>


using namespace std;



int main()
{
	bool ok;

	LinkedList myList;
	myList.add(4);
	myList.add(3);
	myList.add(9);

	myList.remove(1, ok);
	cout << myList << endl;


	system("PAUSE");

	return 0;

}



