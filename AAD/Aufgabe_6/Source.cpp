// Aufgabe_6

#include<iostream>
#include<map>
#include <algorithm>
#include <C:\git\RunProject\RunProject\myHeader.h>
using namespace std;





int main(int argc, char **argv) {


	Graph g;
	g.randomInit(12, 2);
	cout << g << endl;

	cout << g.allNodeAreReachable2(&g,2) << endl;

	system("PAUSE");
	return 0;
}

