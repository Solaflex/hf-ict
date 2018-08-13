#include<string>

using namespace std;

class Message {
private:
	string value;
	int classification;

public:
	const string GetValue();
	void SetValue(string value);

	const int GetClassification();
	void SetClassification(int classification);
	
};

class Classifier {
public:
	Message* const classifyMessages(string *messages, int size);

};