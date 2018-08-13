// BeispielExam_2_1

#include <iostream>
#include <string>
#include <vector>
#include <C:\git\RunProject\RunProject\myHeader.h>


using namespace std;



int main()
{

	Message *myMessage;
	Classifier myClassifier;

	const int ARRAY_SIZE = 5;

	string myStringArray[ARRAY_SIZE] = { "hallo", "cash", "ist Jan", "casgh", "Wächter" };
	
	myMessage = myClassifier.classifyMessages(myStringArray, ARRAY_SIZE);

	cout << myMessage[1].GetValue() << endl;
	cout << myMessage[1].GetClassification() << endl;


	system("PAUSE");

	return 0;

}



