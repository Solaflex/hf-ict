#include <vector>

using namespace std;
class Node {
public:
	Node * left;
	Node * right;
	int value;
	Node(int value);
};

class BinaryTree {
private:
	Node * root;
	void insert(int v, Node * n);
	void height(Node * n, int & ch, int & max);
	void postOrder(Node * n);
	int sum(Node *n);
	void printLeaves(Node *node, vector<int> &s);
public:
	BinaryTree();
	void insert(int v);
	int height();
	void postOrder();
	int sum();
	void printLeaves();

};