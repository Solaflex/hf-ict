// Prüfung_QuickSort_SelectionSort
#include <C:\git\RunProject\RunProject\myHeader.h>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;


int main()
{
	vector<int> data;
	for (int i = 0; i<1000; ++i) {
		//data.push_back(rand()%1000);
		data.push_back(i);
	}

	//print(data);
	Sort *s = new QuickSort();
	clock_t start, stop;
	start = clock();
	s->sort(data);
	stop = clock();
	cout << (double)(stop - start) / CLOCKS_PER_SEC << endl;
	//print(data);

	system("PAUSE");

	return 0;

}



