#include <iostream> 
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>

#include <ctime>


using namespace std;


int main()
{
	
	string s1 = "WillIamShakespeare", s2 = "IamaWeakishSpeller";

	StringUtil StringUtil;
	cout << StringUtil.anagramCheck(s1, s2) << endl;

	
	system("PAUSE");

	return 0;

}



