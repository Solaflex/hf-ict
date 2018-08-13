#include <C:\git\RunProject\RunProject\myHeader.h>

int ArrayUtil::highestProduct(int *values, const int ARRAY_SIZE) {

	
	// Create an internal array
	int TOP[3];


	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << values[i] << endl;
		if (values[i] > TOP[0]) {
			TOP[2] = TOP[1];
			TOP[1] = TOP[0];
			TOP[0] = values[i];
		}
		else if (values[i] > TOP[1]) {
			TOP[2] = TOP[1];
			TOP[1] = values[i];
		}
		else if (values[i] > TOP[2]) {
			TOP[2] = values[i];
		}
	}

	cout << "================" << endl;
	cout << "TOP0: " << TOP[0] << endl;
	cout << "TOP1: " << TOP[1] << endl;
	cout << "TOP2: " << TOP[2] << endl;
	
	return (TOP[0] * TOP[1] * TOP[2]);
}