#include <C:\git\RunProject\RunProject\myHeader.h>
#include <vector>
#include <iostream>

using namespace std;

void QuickSort::sort(vector<int> & data) {
	// Abbruchbedingung
	if (data.size() <= 1) return;

	// pivot element bestimmen
	int randIndex = rand() % data.size();
	int pivot = data[randIndex];
	data[randIndex] = data[data.size() - 1];
	data[data.size() - 1] = pivot;

	// split in linke und rechte haelfte
	vector<int> left;
	vector<int> right;
	for (int i = 0; i<data.size() - 1; i++) {
		if (data[i] < pivot) {
			left.push_back(data[i]);
		}
		else {
			right.push_back(data[i]);
		}
	}

	// rekursiver aufruf
	sort(left);
	sort(right);

	// merge
	int index = 0;
	for (index = 0; index<left.size(); index++) {
		data[index] = left[index];
	}
	data[index] = pivot;
	for (int i = 0; i<right.size(); i++) {
		data[index + i + 1] = right[i];
	}
}

class SelectionSort : public Sort {
public:
	virtual void sort(vector<int> & data);
};

void SelectionSort::sort(vector<int> & data) {
	for (int i = 0; i<data.size() - 1; ++i) {
		int value = data[i];
		int index = i;
		for (int j = i + 1; j<data.size(); ++j) {
			if (value > data[j]) {
				value = data[j];
				index = j;
			}
		}
		int tmp = data[i];
		data[i] = value;
		data[index] = tmp;
	}
}

void print(vector<int> & data) {
	vector<int>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		cout << *it << ",";
	}
	cout << endl;
}