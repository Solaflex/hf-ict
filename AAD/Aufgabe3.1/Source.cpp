// Aufgabe3.1

#include <iostream>
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>


using namespace std;


int main()
{


	// Define array size and content
	const int ARRAY_SIZE = 7;
	const double coins[7] = { 5,2,1,0.5,0.2,0.1,0.05 };


	// Define object and call function
	CoinCombination myCoinCalculator;
	myCoinCalculator.printCoinCombination(1.2, coins, ARRAY_SIZE);

	system("PAUSE");

	return 0;

}



