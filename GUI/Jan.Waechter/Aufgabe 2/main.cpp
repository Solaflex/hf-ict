#include <QCoreApplication>

#include <iostream>

using namespace std;


vector<int>objectdone;

int BSFSearch(vector<vector<int>> graph, int start, int end, int counter){
    counter++;
    vector<int>currentposition = graph.at(start);
    for(int i:currentposition){
        if(i==end){
            return counter;
        }
    }

    for(int i:currentposition){
        counter = BSFSearch(graph, i, end, counter);
    }
    return counter--;
}

int DFSSearch(vector<vector<int>> graph, int start, int end, int counter){
    counter++;
    vector<int>currentposition = graph.at(start);
    if(start==end){
        return counter;
    } else {
        for(int i:currentposition){
            counter = DFSSearch(graph, i, end, counter);
        }
    }

    return counter--;

}


int compare (vector<vector<int>> graph, int start, int end){

    int BSFValue, DFSValue;
    //BSFValue = BSFSearch(graph, start, end, 0);  Generiert Loop, Zeit war abgelaufen um 11:30
    // DFSValue = DFSSearch(graph, start, end, 0); Gibt Exception, Zeit war abgelaufen um 11:30

    if(BSFValue < DFSValue) {
        return 1;
    } else if (DFSValue < BSFValue){
        return 2;
    } else {
        return 3;
    }


}


int main(int argc, char *argv[])
{

    vector<vector<int>> myGraph;
    vector<int>Node1;
    Node1.push_back(1);
    Node1.push_back(3);
    myGraph.push_back(Node1);

    vector<int>Node2;
    Node2.push_back(0);
    Node2.push_back(3);
    myGraph.push_back(Node2);

    vector<int>Node3;
    Node3.push_back(0);
    Node3.push_back(1);
    myGraph.push_back(Node3);

    vector<int>Node4;
    Node2.push_back(0);
    Node2.push_back(1);
    Node2.push_back(2);
    myGraph.push_back(Node2);

    cout << compare(myGraph, 0,2) << endl;



    QCoreApplication a(argc, argv);
    return a.exec();
}
