#include <iostream> 
#include <string>
#include <C:\git\hf-ict\OOP\RunProject\RunProject\myHeader.h>

#include <ctime>


using namespace std;



template <class T>
T getLowestNumber(T *array, int size) {
	T lowestNumber = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < lowestNumber) {
			lowestNumber = array[i];
		}
	}
	return lowestNumber;
}

int* createRandomArray(int size) {
	int *result = new int[size];
	for (int i = 0; i < size; i++) {
		result[i] = rand() % 1000;
	}
	return result;
}

void printArray(int *array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}

class Data {
	int value;
public:
	Data();
	int getValue();
	void setValue(int value);
};

Data::Data() {}

void Data::setValue(int value) {
	this->value = value;
}

int Data::getValue() {
	return this->value;
}

Data* createRandomDataArray(int size) {
	Data *result = new Data[size];
	for (int i = 0; i < size; i++) {
		result[i].setValue(rand() % 1000);
	}
	return result;
}


int main()
{
	srand(time(0));
	const int SIZE = 10;
	int *array = createRandomArray(SIZE);
	printArray(array, SIZE);

	int minElement = getLowestNumber<int>(array, SIZE);
	cout << minElement << endl;

	double dValues[] = { 1.2,3.4,1.1 };
	double dMinElement = getLowestNumber<double>(dValues, 3);
	cout << "double min element: " << dMinElement << endl;

	char cValues[] = { 'b','c','z','a','g' };
	double cMinElement = getLowestNumber<char>(cValues, 5);
	cout << "char min element: " << cMinElement << endl;

	string sValues[] = { "ccc", "djfn", "dkfjdk","aaa", "kjkjk"};
	string sMinElement = getLowestNumber<string>(sValues, 5);
	cout << "string min element: " << sMinElement << endl;


	Data *array = createRandomDataArray(5);
	Data minElement = getLowestNumber<Data>(array, 5);


	system("PAUSE");

	return 0;

}



