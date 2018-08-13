#include <array>

using namespace std;

class PriorityQueue {
private:
	array<int, 1000> values;
	int index;
public:
	PriorityQueue();
	int extractMin();
	void insert(int value);
	int size();
	void print();
};