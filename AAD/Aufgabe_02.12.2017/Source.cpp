// Aufgabe_02.12.2017

#include<iostream>
#include <vector>

#include <C:\git\RunProject\RunProject\myHeader.h>
using namespace std;

string generateSequence(int size) {
	vector<char> ch = { 'A','G','C','T' };
	string result = "";
	for (int i = 0; i<size; i++) {
		int r = rand() % ch.size();
		result += ch[r];
	}
	return result;
}

int match(string t, string p) {
	// YOUR CODE

	bool StringCheck = false;
	int pcounter = 0, finalindex = 0;
	for (int i = 0; i < t.size(); i++) {
		if (pcounter == p.size()) {
			return finalindex;
		}

		if (t.at(i) == p.at(pcounter)) {
			if (!StringCheck) {
				finalindex = i;
			}
			StringCheck = true;
			pcounter++;
		}
		else {
			StringCheck = false;
			pcounter = 0;
		}

			
	}

	return -1;

}

int main(int argc, char **argv) {

	string t = generateSequence(100);
	string p = "CCCGGA";

	cout << match(t, p) << endl;

	system("PAUSE");
	return 0;
}

