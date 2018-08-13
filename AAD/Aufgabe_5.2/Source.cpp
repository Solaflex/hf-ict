// Aufgabe_5.2

#include<iostream>
#include <C:\git\RunProject\RunProject\myHeader.h>
using namespace std;

class TreeUtil {
public:
	static bool isBinarySearchTree(vector<int> values);
};

bool TreeUtil::isBinarySearchTree(vector<int> values) {


	vector<int>::iterator it;
	int index = 0, maxindex= values.end() - values.begin(), value_node, value_left = 0, value_right = 0;

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
		if (value_left >= value_node && value_right != NULL) {
			return false;
		}
	}

	return true;
}



int main(int argc, char **argv) {

	vector<int> v = { 20,12,34,13,19,29 };
	TreeUtil util;

	cout << util.isBinarySearchTree(v) << endl;


	system("PAUSE");
	return 0;
}

