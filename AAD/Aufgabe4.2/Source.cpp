// Aufgabe4.2

#include <iostream>
#include <string>
#include <vector>
#include <C:\git\RunProject\RunProject\myHeader.h>


using namespace std;



int main()
{
	Result myResult;
	ArrayUtil myArrayUtil;

	vector<int> myInput = { 100,101,0,-55,5,6,7 };

	myResult = myArrayUtil.analyseArray(myInput);

	cout << "Positive: " << myResult.nPositive << "%" << endl;
	cout << "Zero: " << myResult.nZero << "%" << endl;
	cout << "Negative: " << myResult.nNegative << "%" << endl;

	system("PAUSE");

	return 0;

}



