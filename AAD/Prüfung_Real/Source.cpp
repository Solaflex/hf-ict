// Prüfung_Real

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <ctime>
#include <sstream>

using namespace std;


bool wordgame(string s1, string s2) {

	vector <string> VectorString1;
	vector <string> VectorString2;

	int lastspace = -1;
	for (int i = 0; i < s1.length(); i++) {

		if (i == s1.size() - 1) {
			VectorString1.push_back(s1.substr(lastspace + 1, i - lastspace));
			lastspace = i;
		}
		else if (s1.at(i) == ' ') {
			VectorString1.push_back(s1.substr(lastspace + 1, i - lastspace - 1));
			lastspace = i;
		}
	}

	lastspace = -1;
	for (int i = 0; i < s2.length(); i++) {
		if (i == s2.size() - 1) {
			VectorString2.push_back(s2.substr(lastspace + 1, i - lastspace));
			lastspace = i;
		}
		else if (s2.at(i) == ' ') {
			VectorString2.push_back(s2.substr(lastspace + 1, i - lastspace - 1));
			lastspace = i;
		}
	}

	for (int i = 0; i < VectorString1.size(); i++) {
		for (int y = 0; y < VectorString2.size(); y++) {
			if (VectorString1[i] == VectorString2[y]) {
				VectorString1.at(i) = "";
				VectorString2.at(y) = "";
			}
		}
	}

	bool VectorEmpty = true;
	for (int i = 0; i < VectorString2.size(); i++) {
		if (VectorString2.at(i) != "") {
			VectorEmpty = false;
		}
	}



	return VectorEmpty;

}
 

// Die Funktion wird 29x rekursiv aufgerufen.
// 1x von der Main, 29x rekurisv

double calculateValue(double Divider) {

	double result = (1 / Divider);

	if (result >= (1 / (pow(2, 28)))) {
		cout << " 1/" << Divider << " = " << result << endl;
		return (result + calculateValue(Divider * 2));
	}
	else {
		return 0;
	}
}



class Pair {
public:
	int min, max;
};

Pair getMinMax(vector<int> values) {

	Pair ReturnPair;

	sort(values.begin(), values.end());

	ReturnPair.max = values[values.size() - 1] + values[values.size() - 2] + values[values.size() - 3] + values[values.size() - 4];
	ReturnPair.min = values[0] + values[1] + values[2] + values[3];

	return ReturnPair;

}



int main(int argc, char **argv) {

	// Aufgabe 1
	//string s1 = "heute ist ein schoener tag tag";
	//string s2 = "heute  tag tag";
	//cout << wordgame(s1, s2) << endl;


	// Aufgabe 2
	// Die Funktion wird 29x rekursiv aufgerufen.
	// 1x von der Main, 29x rekurisv

	//cout << calculateValue(1) << endl;



	// Aufgabe 3
	//vector<int> myVector = {1,2,3,4,5};
	//Pair myPair = getMinMax(myVector);
	//cout << "Max: " << myPair.max << " | Min: " << myPair.min << endl;


	return 0;
}





