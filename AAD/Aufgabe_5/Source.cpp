// Aufgabe_5

#include<iostream>
#include<map>
#include <algorithm>
#include <C:\git\RunProject\RunProject\myHeader.h>
using namespace std;

class TreeUtil {
private:
	static int sumdata(vector<int> v);
	static void printMaximumPath(vector<int> &s);
public:
	static bool isBinarySearchTree(vector<int> values);
	static void printMaximumPath(vector<int> values);
};

bool TreeUtil::isBinarySearchTree(vector<int> values) {


	vector<int>::iterator it;
	int index = 0;
	int maxindex = values.end() - values.begin();
	int value_node, value_left, value_right;

	for (it = values.begin(); it != values.end(); it++) {
		// Get the current index
		index = it - values.begin();

		// assign the values
		value_node = *it;

		// check if calculated node is out of range
		if ((2 * index + 2) < maxindex) {
			value_right = values.at(2 * index + 2);
		}
		else {
			value_right = NULL;
		}

		// check if calculated node is out of range
		if ((2 * index + 1) < maxindex) {
			value_left = values.at(2 * index + 1);
		}
		else {
			value_left = NULL;
		}

		// Compare the values against the standarts of a binary search tree
		if (value_right < value_node && value_right != NULL) {
			return false;
		}
		if (value_left >= value_node && value_left != NULL) {
			return false;
		}
	}

	return true;
}

int TreeUtil::sumdata(vector<int> v) {
	int result = 0;
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		result += *it;
	}
	return result;
}

void TreeUtil::printMaximumPath(vector<int> &s) {

}

void TreeUtil::printMaximumPath(vector<int> values) {

	vector<int>::iterator it;
	int index = 0;
	int maxindex = values.end() - values.begin();
	int value_node, value_left, value_right;

	for (it = values.begin(); it != values.end(); it++) {
		// Get the current index
		index = it - values.begin();

		// assign the values
		value_node = *it;

		// check if calculated node is out of range
		if ((2 * index + 2) < maxindex) {
			value_right = values.at(2 * index + 2);
		}
		else {
			value_right = NULL;
		}

		// check if calculated node is out of range
		if ((2 * index + 1) < maxindex) {
			value_left = values.at(2 * index + 1);
		}
		else {
			value_left = NULL;
		}

		// return if we have reached a leaf
		if (value_right == NULL && value_left == NULL) {
			return;
		}

	}
}


int calculate(string input) {
	int returnvalue = 0;

	map<int, int> charmap;

	// string to lower
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	
	// transform the ASCII char number to a number between 1..26 and increase this counter
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) != ' ') {
			charmap[input.at(i) - 95] += 1;
		};
	}

	// Define a vector
	vector<int> charvalues;

	// Put all values into the vector
	map<int, int>::iterator it;
	for (it = charmap.begin(); it != charmap.end(); it++) {
		charvalues.push_back(it->second);
	}

	// Sort the vector
	sort(charvalues.begin(), charvalues.end());

	// Revert the vector
	reverse(charvalues.begin(), charvalues.end());

	int index = 0;
	// Calculate the value from 26 backwards
	for (int i = 26; i > (26 - charvalues.size()); i--) {
		returnvalue += (charvalues.at(index) * i);
		index++;
	}
	return returnvalue;
}

int main(int argc, char **argv) {

	// Aufgabe 2
	vector<int> v = { 20,12,34,9,21,29 };
	TreeUtil util;

	cout << util.isBinarySearchTree(v) << endl;
	

	/* Aufgabe 3
	vector<int> v = { 40,100,200,20,40,70,80,50,10 };
	TreeUtil util;

	util.printMaximumPath(v);
*/
	


	/* Aufgabe 4
	string test = "ABBCCC";
	string test2 = "Sometimes test cases are hard to make up";

	cout << calculate(test2) << endl;

	*/




	system("PAUSE");
	return 0;
}

