#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <sstream>
#include <array>
using namespace std;

class Graph {
private:
	vector< vector<int> > neighbours;
	vector< vector<int> > weights;

	void DFSParse(Graph *graph, int currentnode, vector<bool>&visited);
public:
	Graph();
	void randomInit(int nNodes = 10, int nConnections = 15, bool directed = false);
	int getNumberOfNodes();
	vector<int> getNeighbours(int node);
	vector<int> getWeights(int node);

	friend std::ostream& operator<<(std::ostream& s, const Graph & obj);

	bool allNodeAreReachable(Graph *graph, int start);
	bool allNodeAreReachable2(Graph *graph, int start);
	void SearchThroughNodes(Graph *graph, int start, vector<int>&PassedNodes);

	int shortestReach(Graph *graph, int start, int end);
	void shortestReach(Graph *graph, int start, int end, vector<int>&PathCounter, int Path);

};

std::ostream& operator<<(std::ostream& s, const Graph & obj);





#endif

#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H

#include <vector>
using namespace std;

class Graph;

class DijkstraEntry {
public:
	int node;
	int distance;
	bool marked;
	int predecessor;
};

class GraphUtil {
private:
	static void GraphUtil::dijkstra(Graph *g, int start, vector<DijkstraEntry> &v);
public:
	static vector<DijkstraEntry> dijkstra(Graph *g, int start);

};

#endif
