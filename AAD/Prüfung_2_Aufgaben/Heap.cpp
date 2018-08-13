#include <C:\git\RunProject\RunProject\Heap.h>
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue() : index(0) {
}

void PriorityQueue::print() {
	for (int i = 0; i<index; i++) {
		cout << values[i] << ",";
	}
	cout << endl;
}

int PriorityQueue::extractMin() {
	int result = values[0];
	index--;
	values[0] = values[index - 1];

	// check heap condition
	int root = 0;
	bool change = true;
	while (change) {
		change = false;
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int changeIndex;
		if (left >= index) return result;
		if (right >= index) {
			if (values[root] > values[left]) {
				change = true;
				changeIndex = left;
			}
		}
		else {
			if (values[root] >= values[left] && values[left] <= values[right]) {
				change = true;
				changeIndex = left;
			}
			else if (values[root] >= values[right] && values[right] < values[left]) {
				change = true;
				changeIndex = right;
			}
		}

		if (change) {
			int swp = values[changeIndex];
			values[changeIndex] = values[root];
			values[root] = swp;
			root = changeIndex;
		}
	}

	return result;
}

void PriorityQueue::insert(int value) {
	values[index] = value;

	// move up if needed
	int parent = (index - 1) / 2;
	int i = index;
	bool change = true;

	while (parent >= 0 && change) {
		change = false;
		if (values[parent] > values[i]) {
			int swp = values[i];
			values[i] = values[parent];
			values[parent] = swp;
			change = true;
			i = parent;
			parent = (parent - 1) / 2;
		}
	}
	index++;
}

int PriorityQueue::size() {
	return index;
}
