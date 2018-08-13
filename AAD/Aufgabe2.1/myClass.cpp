#include <C:\git\RunProject\RunProject\myHeader.h>


int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE) {

	int CurrentMinuteValue, NextMinuteValue, MaxProfit = 0, Profit = 0;

	// Go through the array
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		// Store the values
		CurrentMinuteValue = values[i];
		NextMinuteValue = values[i+1];

		cout << "Current Value: " << CurrentMinuteValue << " | Next Minute Value: " << NextMinuteValue << " | ";

		// Compare the values
		if (NextMinuteValue > CurrentMinuteValue) {
			// We have an increased value. Add the profit
			Profit = (NextMinuteValue - CurrentMinuteValue);
			MaxProfit += Profit;
			cout << "BUY/STAY:   Profit " << Profit << " | New MaxProfit: " << MaxProfit << endl;
		}
		else if (NextMinuteValue < CurrentMinuteValue) {
			// We have a decreased value. 
			Profit = 0;
			cout << "SELL/LEAVE " << endl;
		}
		else {
			// We have the same value
			cout << "KEEP" << endl;
		}



	}



	return MaxProfit;
}