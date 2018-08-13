// Aufgabe3.3

#include <iostream>
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>


using namespace std;



int main()
{


	string s1 = "o8fgp8gp8fgp87fgp8g7pp6trp0rfp86zfdp8";
	string s2 = "684ei75de85ifgp87fgp8g7 pp6trp0e58e6di95ei95ei95";

	string result = StringUtil::lcs(s1, s2);
	cout << "---------result-----------" << endl;
	cout << result << endl;


	system("PAUSE");

	return 0;

}



