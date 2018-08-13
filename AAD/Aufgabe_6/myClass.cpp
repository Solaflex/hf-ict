#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <array>
#include <C:\git\RunProject\RunProject\myHeader.h>

using namespace std;

Graph::Graph() {
}

void Graph::randomInit(int nNodes, int nConnections, bool directed) {
	vector<int> v;
	for (int i = 0; i<nNodes; i++) {
		neighbours.push_back(v);
	}
	int counter = 0;
	while (counter < nConnections) {
		int source = rand() % nNodes;
		int target = rand() % nNodes;
		if (source != target) {
			if (find(neighbours[source].begin(), neighbours[source].end(), target) == neighbours[source].end()) {
				neighbours[source].push_back(target);
				if (!directed) {
					neighbours[target].push_back(source);
				}
				counter++;
			}
		}
	}
	for (int i = 0; i<nNodes; i++) {
		sort(neighbours[i].begin(), neighbours[i].end());
	}

	for (vector<int> v : neighbours) {
		vector<int> w;
		for (int i = 0; i<v.size(); i++) {
			int cost = rand() % 20 + 1;
			w.push_back(cost);
		}
		weights.push_back(w);
	}

	if (!directed) {
		for (int i = 0; i<weights.size(); i++) {
			for (int j = 0; j<weights.at(i).size(); j++) {
				int source = i;
				int target = neighbours.at(i).at(j);
				int weight = weights.at(i).at(j);
				int index = find(neighbours.at(target).begin(), neighbours.at(target).end(), source) - neighbours.at(target).begin();
				weights[target][index] = weight;
			}
		}
	}
}

int Graph::getNumberOfNodes() {
	return neighbours.size();
}

vector<int> Graph::getNeighbours(int node) {
	return neighbours.at(node);
}

vector<int> Graph::getWeights(int node) {
	return weights.at(node);
}

std::ostream& operator<<(std::ostream& s, const Graph & obj) {
	for (int i = 0; i<obj.neighbours.size(); i++) {
		vector<int>::iterator it;
		s << "Node " << i << "\t";
		for (int j = 0; j<obj.neighbours[i].size(); j++) {
			s << obj.neighbours[i].at(j) << "(" << obj.weights[i].at(j) << "), ";
		}
		s << endl;
	}
	return s;
}



bool Graph::allNodeAreReachable2(Graph *graph, int start) {
	//bool *visited = new bool[graph->getNumberOfNodes()]();

	vector<bool>visited(graph->getNumberOfNodes());
	DFSParse(graph, start, visited);

	for (bool b : visited) {
		if (!b) {
			return false;
		}
	}

	return true;
}

void Graph::DFSParse(Graph *graph, int currentnode, vector<bool>&visited) {

	visited[currentnode] = true;

	for (int n : graph->getNeighbours(currentnode)) {
		if (!visited[n]) {
			DFSParse(graph, n, visited);
		}
	}
}


// Aufgabe 1
bool Graph::allNodeAreReachable(Graph *graph, int start) {

	vector<int>PassedNodes;

	PassedNodes.push_back(start);

	for (int i = 0; i < graph->neighbours.at(start).size();i++) {
		SearchThroughNodes(graph, graph->neighbours.at(start).at(i), PassedNodes);
	}

	if (PassedNodes.size() == graph->neighbours.size()) {
		return true;
	}
	else {
		return false;
	}

}
// Recursive function
void Graph::SearchThroughNodes(Graph *graph, int start, vector<int>&PassedNodes) {

	if (std::find(graph->neighbours.at(start).begin(), graph->neighbours.at(start).end(), start) != graph->neighbours.at(start).end())
	{
		return;
	}
	else {
		PassedNodes.push_back(start);
		for (int i = 0; i < graph->neighbours.at(start).size(); i++) {
			SearchThroughNodes(graph, graph->neighbours.at(start).at(i), PassedNodes);
		}		
	}
	return;
}


// Aufgabe 2

int Graph::shortestReach(Graph *graph, int start, int end) {

	vector<int>PathCounter;

	for (int i = 0; i < graph->neighbours.at(start).size(); i++) {
		PathCounter.push_back(1);
		shortestReach(graph, graph->neighbours.at(start).at(i),end, PathCounter,i);
	}

	return 0;

}
// Recursive function
void Graph::shortestReach(Graph *graph, int start, int end, vector<int>&PathCounter, int Path) {

	if (graph->neighbours.at(start).size() == 0) {
		PathCounter.at(Path)--;
		return;
	}

	if (start == end)
	{
		PathCounter.at(Path)--;
		return;
	}
	else {
		PathCounter.at(Path)++;
		for (int i = 0; i < graph->neighbours.at(start).size(); i++) {
			shortestReach(graph, graph->neighbours.at(start).at(i), end, PathCounter, i);
		}

		// Problem: Loop

	}

}


// Aufgabe 3
/*
	- Rekursive Funktion mit bool als return und Call-By-Reference vector
	- Node nummer in vector eintragen, rekuriv aufrufen
	- Falls aktuelle node = ziel node dann return true
	- Falls return true, return true. Falls return false, letzten Eintrag im vector löschen
*/

// Aufgabe 4
/*
	- Durch jede Node gehen und für jede mögliche Zielnode die Aufgabe 3 aufrufen
	- Alle Resultate sammeln und den vector zurückgebene

*/


vector<DijkstraEntry> GraphUtil::dijkstra(Graph *g, int start) {

	vector<DijkstraEntry> v;
	DijkstraEntry d;

	// init the dijkstra vector
	for (int i = 0; i<g->getNumberOfNodes(); i++) {
		d.node = i;
		d.distance = -1;
		d.marked = 0;
		d.predecessor = -1;
		v.push_back(d);
	}

	// init the first node
	v.at(start).distance = 0;
	v.at(start).predecessor = 0;

	// perform algorithm
	dijkstra(g, start, v);

	// print dijkstra
	cout << "node\tdist\tmarked\tpredecessor" << endl;
	for (int i = 0; i<v.size(); i++) {
		cout << v[i].node << "\t";
		cout << v[i].distance << "\t";
		cout << v[i].marked << "\t";
		cout << v[i].predecessor << "\t";
		cout << endl;
	}

	return v;
}

void GraphUtil::dijkstra(Graph *g, int start, vector<DijkstraEntry> &v) {
	// set neighbours and weights vectors
	vector<int> neigh = g->getNeighbours(start);
	vector<int> weight = g->getWeights(start);

	for (int i = 0; i<neigh.size(); i++) {
		// just set the distance and predecessor 
		// if the distance is not yet set
		if (v[neigh[i]].distance == -1) {
			v[neigh[i]].distance = weight[i];
			v[neigh[i]].predecessor = v[start].node;
			// compare the used nodes distance and target nodes weight
			// against the target nodes distance
			// also check if the target node is not marked yet
			// if true, update the target distance
		}
		else if (v[start].distance + weight[i] < v[neigh[i]].distance && v[neigh[i]].marked != 1) {
			v[neigh[i]].distance = v[start].distance + weight[i];
		}
	}

	// mark the node used node
	v[start].marked = 1;

	// get next node
	// init min as -1
	int minimal(-1);
	for (int i = 0; i<v.size(); i++) {
		bool marked = v[i].marked;
		int distance = v[i].distance;
		// a valid node must not be marked and
		// must have a valid distance (visited)
		if (marked != 1 && distance != -1) {
			// if min is -1 just assign the first node
			if (minimal == -1) {
				minimal = v[i].node;
				// compare for smallest distance
			}
			else if (distance < v[minimal].distance) {
				minimal = v[i].node;
			}
		}
	}
	if (minimal != -1) {
		dijkstra(g, minimal, v);
	}
}
