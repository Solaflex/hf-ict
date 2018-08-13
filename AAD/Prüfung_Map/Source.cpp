// Prüfung_Map
#include <C:\git\RunProject\RunProject\myHeader.h>
#include <iostream>
#include <map>

using namespace std;


int main()
{
	map<int, string> employeeMap;

	// insert
	employeeMap[0] = "HERZIG";
	employeeMap[1] = "BALE";
	employeeMap[0] = "WAYNE"; // old value will be overwritten

	pair < map<int, string>::iterator, bool> ret;
	ret = employeeMap.insert(pair<int, string>(2, "PARKER"));
	// ret.second is true
	ret = employeeMap.insert(pair<int, string>(2, "CLARK"));
	// ret.second is true

	

	// loop through elements
	map<int, string>::iterator iter;
	for (iter = employeeMap.begin(); iter != employeeMap.end(); iter++) {
		int key = iter->first;
		string value = iter->second;
	}

	system("PAUSE");

	return 0;

}



