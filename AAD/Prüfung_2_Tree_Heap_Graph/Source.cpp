// Prüfung_2_Tree_Heap_Graph


#include <C:\git\RunProject\RunProject\myHeader.h>
#include <C:\git\RunProject\RunProject\BinarySearchTree.h>
#include <C:\git\RunProject\RunProject\Graph.h>
#include <C:\git\RunProject\RunProject\GraphUtil.h>

#include<iostream>
using namespace std;


int main(int argc, char **argv) {

	/* Binary Tree Example */

	//BinaryTree newtree;
	//newtree.insert(4);
	//newtree.insert(3);
	//newtree.insert(15);
	//newtree.insert(13);


	//newtree.printLeaves();



	/* Graph Example */

	Graph g;
	g.randomInit(60, 90, true);
	cout << g << endl;

	vector<DijkstraEntry> table = GraphUtil::dijkstra(&g, 0);




	system("PAUSE");
	return 0;
}

