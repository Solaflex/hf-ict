// BeispielExam_1_1
#include<iostream>

#include <C:\git\RunProject\RunProject\myHeader.h>


using namespace std;


int crosssum(unsigned int n) {
	int result = 0;
	int localN = n;
	while (localN > 0) {
		result += localN % 10;
		localN /= 10;
	}

	return result;
}

int crosssum_rek(unsigned int n) {
	int result = 0;
	int localN = n;

	if (localN > 0) {
		result += localN % 10;
		localN /= 10;
		return (result + crosssum_rek(localN));
	}
	else {
		return localN;
	}
}


int main()
{

	cout << crosssum_rek(583) << endl;

	system("PAUSE");

	return 0;

}



