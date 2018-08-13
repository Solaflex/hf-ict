#include <iostream> 
#include <string>
#include <C:\git\RunProject\RunProject\myHeader.h>

#include <ctime>

using namespace std;

LinkedList::LinkedList() : head(0), tail(0) {

}

int LinkedList::get(int index, bool &ok) {
	if (!isIndexValid(index)) {
		ok = false;
	}
	else {
		Node *currentNode = this->head;
		for (int i = 0; i < index; i++)
		{
			currentNode = currentNode->next;
		}
		ok = true;
		return currentNode->value;
	}
}

void LinkedList::set(int index, int value, bool &ok) {
	if (!isIndexValid(index)) {
		ok = false;
	}
	else {
		Node *currentNode = this->head;
		for (int i = 0; i < index; i++)
		{
			currentNode = currentNode->next;
		}
		currentNode->value = value;
		ok = true;
	}
}

void LinkedList::add(int value) {
	Node *node = new Node();
	node->value = value;
	node->next = 0;

	if (head == 0) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		tail = node;
	}
}

void LinkedList::remove(int index, bool &ok) {
	if (!isIndexValid(index)) {
		ok = false;
	}
	else {
		if (index == 0) {
			Node *toDelete = head;
			head = head->next;
			delete toDelete;
		}
		else {
			Node *currentNode = head;
			for (int i = 0; i < index - 1; i++) {
				currentNode = currentNode->next;
			}
			Node *toDelete = currentNode->next;
			if (toDelete == tail) {
				tail = currentNode;
			}
			currentNode->next = currentNode->next->next;
			delete toDelete;
		}
	}
}

int LinkedList::size() {

	Node *currentNode = this->head;
	int i = 0;
	while (currentNode != 0) {
		i++;
		currentNode = currentNode->next;
	}
	return i;
}

bool LinkedList::isIndexValid(int index) {
	int s = size();
	return index >= 0 && index < s;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& obj) {
	stream << "Head: " << obj.head << endl;
	stream << "Tail: " << obj.tail << endl;
	stream << "========================" << endl;

	Node *currentNode = obj.head;
	int i = 0;
	while (currentNode != 0) {
		stream << "address:" << currentNode << endl;
		stream << "counter:" << i << endl;
		stream << "value:  " << currentNode->value << endl;
		stream << "next:   " << currentNode->next << endl;
		stream << "========================" << endl;
		currentNode = currentNode->next;
		i++;
	}

	return stream;
}
