#include <C:\git\RunProject\RunProject\myHeader.h>
#include <vector>
#include <iostream>


using namespace std;

void CoinCombination::printCoinCombination(double value, const double *coins, const int ARRAY_SIZE) {

	for (int i = 0; i < ARRAY_SIZE;) {
		if (i == ARRAY_SIZE) {
			break;
		}
		if ((value - coins[i]) >= 0) {
			value -= coins[i];
			cout << coins[i] << ",";
		}
		else {
			i++;
		}
	}
	




}