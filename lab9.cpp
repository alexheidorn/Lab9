/*
* Alex Heidorn
* Created: 11/9/23
* CS2 Lab9
*  
*/

/* Input (from txt file):
V1 V2 3
V1 V3 3
V1 V4 3
V2 V3 3
V3 V6 3
V3 V5 3
V4 V5 3

V7 V8 3
V7 V9 3

V10 V11 3
V10 V12 3
*/

/* Output:
File with graph: componentgraph1.txt
Graph:
V1 (0): 1 : 3   2 : 3   3 : 3   
V2 (1): 0 : 3   2 : 3   
V3 (2): 0 : 3   1 : 3   4 : 3   5 : 3   
V4 (3): 0 : 3   5 : 3   
V6 (4): 2 : 3   
V5 (5): 2 : 3   3 : 3   
V7 (6): 7 : 3   8 : 3   
V8 (7): 6 : 3   
V9 (8): 6 : 3   
V10 (9): 10 : 3   11 : 3   
V11 (10): 9 : 3   
V12 (11): 9 : 3

Graph:
Component 1:
V1 (0): 1 : 3   2 : 3   3 : 3
V2 (1): 0 : 3   2 : 3
V3 (2): 0 : 3   1 : 3   4 : 3   5 : 3
V4 (3): 0 : 3   5 : 3
V6 (4): 2 : 3
V5 (5): 2 : 3   3 : 3
Component 2:
V7 (6): 7 : 3   8 : 3
V8 (7): 6 : 3   
V9 (8): 6 : 3
Component 3:
V10 (9): 10 : 3   11 : 3
V11 (10): 9 : 3
V12 (11): 9 : 3
PS C:\Users\alexh\CS2\HW11> 
*/

#include <iostream>
#include <vector>
#include <limits>
#include "HeidornGraph.cpp"
using namespace std;

int main() {
    string fileName;
    cout << "File with graph: ";
    cin >> fileName;
    Graph g;
    if (g.readUndirectedGraph(fileName)) {
        g.showGraph();

        g.showComponents();
    }
    else {
        cout << "Unable to open file " << fileName << "\n";
    }
    return 0;
}