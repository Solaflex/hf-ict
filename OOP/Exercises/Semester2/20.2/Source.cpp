#include<string>
#include<iostream>
#include<myHeader.h>


using namespace std;

int main()
{
	
	myClass TestClass = myClass();
	TestClass.setValue(5);
	TestClass.showValue();
	
	
	system("PAUSE");
	return 0;
}