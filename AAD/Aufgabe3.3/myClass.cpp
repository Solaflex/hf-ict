#include <iostream>
#include <string>

#include <C:\git\RunProject\RunProject\myHeader.h>

using namespace std;

string StringUtil::lcs(string input1, string input2) {
	string tmp("");
	for (int i = input1.size(); i>0; i--) {
		for (int j = 0; j<input1.size() && j + i <= input1.size(); j++) {
			tmp = input1.substr(j, i);
			cout << tmp << endl;
			if (input2.find(tmp) != string::npos) {
				return tmp;
			}
		}
	}
	return "";
}
