#include <vector>

using namespace std;

class Sort {
public:
	virtual void sort(vector<int> & data) = 0;
};

class QuickSort : public Sort {
public:
	virtual void sort(vector<int> & data);
};