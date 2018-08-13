// Prüfung_BinaryTree

#include <iostream>
#include <cstdlib>
#include <C:\git\RunProject\RunProject\myHeader.h>
using namespace std;

class Node {
public:
	int value;
	Node * left;
	Node * right;
	Node(int value);
};

Node::Node(int value) : value(value), left(0), right(0) {
}

class BinaryTree {
private:
	Node * root;
	void insert(int element, Node * node);
	int height(int level, Node *node);
public:
	BinaryTree();
	void insert(int element);
	int height();
};

BinaryTree::BinaryTree() : root(0) {
}

void BinaryTree::insert(int element) {
	if (root == 0) {
		root = new Node(element);
	}
	else {
		insert(element, root);
	}
}

void BinaryTree::insert(int element, Node * node) {
	if (node->value > element) {
		if (node->left == 0) {
			node->left = new Node(element);
		}
		else {
			insert(element, node->left);
		}
	}
	else {
		if (node->right == 0) {
			node->right = new Node(element);
		}
		else {
			insert(element, node->right);
		}
	}
}



int BinaryTree::height() {
	if (root == 0) {
		return 0;
	}
	else {
		return height(1, root);
	}
}

int BinaryTree::height(int level, Node *Node) {
	int LevelLeft = level, LevelRight = level;
	if (Node->left != 0) {
		LevelLeft = height(level + 1, Node->left);
	}
	else if (Node->right != 0) {
		LevelRight = height(level + 1, Node->right);
	}

	if (LevelLeft > level) {
		return LevelLeft;
	}
	else if (LevelRight > level) {
		return LevelRight;
	}
	else {
		return level;
	}

}


int main(int argc, char **argv) {
	BinaryTree bt;

	for (int i = 0; i<1000000; i++) {
		bt.insert(rand());
	}

	cout << bt.height() << endl;

	system("PAUSE");

	return 0;
}

