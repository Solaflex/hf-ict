#include <iostream>
#include <string>
#include <vector>

#include <C:\git\RunProject\RunProject\myHeader.h>

using namespace std;

Result::Result() {
	cout << "Konstruktor" << endl;
}

Result ArrayUtil::analyseArray(vector<int> input) {

	Result ReturnResult;
	int PositiveCounter = 0, ZeroCounter = 0, NegativeCounter = 0, TotalCounter = 0;

	vector<int>::iterator it;
	for (it = input.begin(); it != input.end(); it++) {
		// Increase the total counter
		TotalCounter++;

		// Compare the number
		if (*it < 0) {
			NegativeCounter++;
		}
		else if (*it == 0) {
			ZeroCounter++;
		}
		else {
			PositiveCounter++;
		}
	}

	// Calculate the percentage. Multiply with 100 to reduce rounding issues
	ReturnResult.nNegative = (NegativeCounter * 100.0) / TotalCounter;
	ReturnResult.nZero = (ZeroCounter * 100.0) / TotalCounter;
	ReturnResult.nPositive = (PositiveCounter * 100.0) / TotalCounter;

	return ReturnResult;

}

