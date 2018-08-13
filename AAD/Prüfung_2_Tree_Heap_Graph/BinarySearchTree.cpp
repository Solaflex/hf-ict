#include <iostream>
#include <cstdlib>
#include <vector>
#include <C:\git\RunProject\RunProject\BinarySearchTree.h>


using namespace std;

Node::Node(int value) : value(value), left(0), right(0) {
}

BinaryTree::BinaryTree() : root(0) {
}


int BinaryTree::sum(Node *n) {
	if (n == 0) return 0;
	int v = n->value;
	return sum(n->left) + v + sum(n->right);
}

int BinaryTree::sum() {
	return sum(root);
}

void BinaryTree::postOrder() {
	postOrder(root);
	cout << endl;
}

void BinaryTree::postOrder(Node * n) {
	if (n != 0) {
		postOrder(n->left);
		postOrder(n->right);
		cout << n->value << ",";
	}
}

int BinaryTree::height() {
	int ch = 0;
	int max = 0;
	height(root, ch, max);
	return max;
}

void BinaryTree::height(Node * n, int & ch, int & max) {
	if (n == 0) {
		if (ch > max) {
			max = ch;
		}
	}
	else {
		ch++;
		height(n->left, ch, max);
		height(n->right, ch, max);
		ch--;
	}
}

void BinaryTree::insert(int v, Node * n) {
	if (v < n->value) {
		// left
		if (n->left == 0) {
			n->left = new Node(v);
		}
		else {
			insert(v, n->left);
		}
	}
	else {
		// right
		if (n->right == 0) {
			n->right = new Node(v);
		}
		else {
			insert(v, n->right);
		}
	}
}

void BinaryTree::insert(int v) {
	if (root == 0) {
		root = new Node(v);
	}
	else {
		insert(v, root);
	}
}


int sumdata(vector<int> v) {
	int result = 0;
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		result += *it;
	}
	return result;
}

void BinaryTree::printLeaves(Node *node, vector<int> &s) {
	if (node == 0) return;
	s.push_back(node->value);
	if (node->left == 0 && node->right == 0) {

		for (int i = 0; i<s.size(); i++) {
			cout << s[i] << ",";
		}
		cout << " sum: " << sumdata(s);
		cout << endl;

	}
	else {
		printLeaves(node->left, s);
		printLeaves(node->right, s);
	}

	s.pop_back();
}

void BinaryTree::printLeaves() {
	vector<int> s;
	printLeaves(root, s);
	cout << endl;
}



