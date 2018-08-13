#include <C:\git\RunProject\RunProject\myHeader.h>
#include <string>
#include <algorithm> // std::transform


using namespace std;

bool StringUtil::isPalindrome(string input){

	// Make the string lowercase to compare it
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	// Store the length of the string for later use
	int length = input.length();

	// Get the first and the last char
	string first = input.substr(0,1);
	string last = input.substr((length - 1), 1);

	// If we have reached the last char or the two last which are equal, return true
	if ((length == 1) || ((first == last) && (length == 2))) {
		return true;
	}
	// Else if compare if they are equal. Because they are longer then two and not an odd number, remove the first
	// and last char and call the function again. Return the return value of the child function.
	else if (first == last) {
		input = input.substr((0 + 1), (length - 2));
		return isPalindrome(input);
	}
	// The first and last char are not equal, return false
	else
	{
		return false;
	}
};