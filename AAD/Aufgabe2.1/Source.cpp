#include <iostream> 
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>

#include <ctime>


using namespace std;


int main()
{
	// 510 is the amount of minutes from 09:00 until 17:30
	const int ARRAY_SIZE = 510;

	// Create an array
	int stockprices[ARRAY_SIZE];

	// True random
	srand(time(NULL));

	int randomvalue = rand() % 150 + 50;
	// Add random prices to the array
	for (int i = 0; i < ARRAY_SIZE; i++) {
		stockprices[i] = randomvalue;

		// Modify the randomvalue between +10 and -10
		randomvalue += (rand() % 20 + (-10));
	}




	Trader MyTrade;
	cout << MyTrade.calculateMaxProfit(stockprices, ARRAY_SIZE) << endl;

	
	system("PAUSE");

	return 0;

}



