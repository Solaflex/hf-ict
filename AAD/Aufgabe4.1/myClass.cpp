#include <iostream>
#include <string>

#include <C:\git\RunProject\RunProject\myHeader.h>

using namespace std;

char StringUtil::getLonelyElement(string input) {

	// Define the size of the ASCII array
	const int ASCII_SIZE = 256;

	// Initialize the ASCII array
	int ASCII[ASCII_SIZE] = { 0 };

	// Go through the string
	for (int i = 0; i < input.size(); i++) {
		// Increase the counter for each ASCII representive
		ASCII[input[i]]++;
	}

	// Go through the ASCII array
	for (int i = 0; i < ASCII_SIZE; i++) {
		// when we have found the array member with only one appearance
		if (ASCII[i] == 1) {
			// return this ASCII number
			return i;
		}
	}
}