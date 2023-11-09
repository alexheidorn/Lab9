/*
* Alex Heidorn
* Created: 11/9/23
* CS2 Lab9
*  
*/

#include <iostream>
#include <vector>
#include <limits>
#include "Graph.cpp"
using namespace std;

int main() {
    string fileName;
    cout << "File with graph: ";
    cin >> fileName;
    Graph g;
    if (g.readUndirectedGraph(fileName)) {
        g.showGraph();
    }
    else {
        cout << "Unable to open file " << fileName << "\n";
    }
    return 0;
}