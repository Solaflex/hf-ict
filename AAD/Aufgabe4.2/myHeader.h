#include <string>
#include <vector>

using namespace std;

class Result {
public:
	Result();
	double nPositive;
	double nZero;
	double nNegative;
};

class ArrayUtil {
public:
	static Result analyseArray(vector<int> input);
};
