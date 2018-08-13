#include <C:\git\RunProject\RunProject\myHeader.h>
#include<string>

using namespace std;

string const Message::GetValue()  {
	return this->value;
}

void Message::SetValue(string value) {
	this->value = value;
}


int const Message::GetClassification() {
	return this->classification;
}

void Message::SetClassification(int classification) {
	this->classification = classification;
}


Message* const Classifier::classifyMessages(string *messages, int size) {

	Message *ReturnArray = new Message[size];

	for (int i= 0; i < size; i++) {		
		ReturnArray[i].SetValue(messages[i]);

		int classificationvalue = 0;
		bool KeyWordFound = false;
		bool DoubleWordFound = false;
		string string = messages[i], secondstring;


		if (string.length() < 12) {
			classificationvalue++;
		}
		

		for (int y = 0; y < size; y++) {
			secondstring = messages[y];
			if (((secondstring == string) && y != i) && DoubleWordFound == false) {
				classificationvalue++;
			}
			if ((string == "cash" || string == "subscribe" || string == "marketing") && KeyWordFound == false) {
				classificationvalue++;
				KeyWordFound = true;
			}
		}

		ReturnArray[i].SetClassification(classificationvalue);
	}

	return ReturnArray;
}

