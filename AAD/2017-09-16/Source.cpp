#include <iostream> ;
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>

#include <ctime>
#include <vector>


using namespace std;


int main()
{
	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	v.insert(v.begin() + 3, 50);

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}



	system("PAUSE");

	return 0;

}



