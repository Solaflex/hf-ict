// Aufgabe4.1

#include <iostream>
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>


using namespace std;



int main()
{
	string myString = "abcdedcba11";
	StringUtil myUtil;

	// Create a char from the ASCII number
	cout << char(myUtil.getLonelyElement(myString)) << endl;



	system("PAUSE");

	return 0;

}



