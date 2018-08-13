class Node {
public:
	int value;
	Node *next;
};


class LinkedList {
	int  *values;
	Node *head;
	Node *tail;

public:
	LinkedList();

	int size();
	void add(int value);
	int get(int index, bool &ok);
	void set(int index, int value, bool &ok);
	void remove(int index, bool &ok);
	bool isIndexValid(int index);
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& obj);
};
