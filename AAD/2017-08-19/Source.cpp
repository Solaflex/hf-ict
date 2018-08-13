#include <iostream> 
#include <string>
#include <C:\git\hf-ict\OOP\RunProject\RunProject\myHeader.h>

#include <ctime>


using namespace std;

char analyse(string s) {

	for (int i = 0; i < s.length(); i++) {
		char rch = s.at(i);
		bool twoSameCharactersFound = false;
		for (int j = 0; j < s.length(); j++) {
			if (i == j) {
				continue;
			}
			char ch = s.at(j);
			if (ch == rch) {
				twoSameCharactersFound = true;
				break;
			}
		}
		if (!twoSameCharactersFound) {
			return rch;
		}
	}
	return '$';
	
}

char analysebetter(string s) {

	int array[26];

	for (int i = 0; i < s.length(); i++)
	{

	}
}

string createRandomString(int size) {
	string result = "";
	for (int i = 0; i < size; i++) {
		char ch = 'A' + rand() % 26;
		result += ch;
	}
	return result;
}


int main()
{

	
	string s = createRandomString(1000);
	cout << s << endl;
	cout << analyse(s) << endl;
	system("PAUSE");

	return 0;

}



