#include <iostream> 
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>

#include <ctime>


using namespace std;


int main()
{
	
	const int ARRAY_SIZE = 10;

	// Create an array
	int ArrayWithNumbers[ARRAY_SIZE];

	// True random
	srand(time(NULL));

	// Add random prices to the array
	for (int i = 0; i < ARRAY_SIZE; i++) {
		ArrayWithNumbers[i] = rand() % 10 + 1;
	}




	ArrayUtil ArrayUtil;
	cout << ArrayUtil.highestProduct(ArrayWithNumbers, ARRAY_SIZE) << endl;

	
	system("PAUSE");

	return 0;

}



