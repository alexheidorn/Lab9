//
// Created by Richard Maclin on 10/23/23.
// Edited by Alex Heidorn 11/14/23
//

#include "HeidornGraph.h"
#include <iostream>
#include <fstream>
#include <stack>

namespace std {
    int Vertex::vertexNumber = 0;

    void Vertex::addEdge(int toV, double w) {
        edges.push_back(Edge(number,toV,w));
    }

    void Vertex::showVertex() {
        cout << name << " (" << number << "): ";
        for (auto e: edges) {
            cout << e.getVertex2() << " : " << e.getWeight() << "   ";
        }
        cout << "\n";
    }

    int Graph::getVertexNumber(string n) {
        for (int i = 0; i < vertexArray.size(); i++) {
            if (n.compare(vertexArray[i].getName()) == 0) {
                return i;
            }
        }
        return -1;
    }

    int Graph::insertVertexName(string n) {
        vertexArray.push_back(Vertex(n));
        return (vertexArray.size() - 1);
    }

    int Graph::getOrInsertVertexName(string n) {
        int ni = getVertexNumber(n);
        if (ni == -1) {
            return insertVertexName(n);
        }
        else {
            return ni;
        }
    }

    void Graph::addEdge(int v1, int v2, double w) {
        vertexArray[v1].addEdge(v2,w);
    }

    bool Graph::readUndirectedGraph(string fileName) {
        ifstream inStream(fileName);
        if (inStream.is_open()) {
            while (inStream.good()) {
                string v1name;
                string v2name;
                double val;
                inStream >> v1name >> v2name >> val;
                int v1 = getOrInsertVertexName(v1name);
                int v2 = getOrInsertVertexName(v2name);
                addEdge(v1,v2,val);
                addEdge(v2,v1,val);

                //assign componens
                findComponents();
            }
            return true;
        }
        else
            return false;
    }

    bool Graph::readDirectedGraph(string fileName) {
        ifstream inStream(fileName);
        if (inStream.is_open()) {
            while (inStream.good()) {
                string v1name;
                string v2name;
                double val;
                inStream >> v1name >> v2name >> val;
                int v1 = getOrInsertVertexName(v1name);
                int v2 = getOrInsertVertexName(v2name);
                cout << v1 << endl;
                cout << v2 << endl;
                addEdge(v1,v2,val);
            }
            return true;
        }
        else
            return false;
    }

    void Graph::showGraph() {
        cout << "Graph:\n";
        for (auto v: vertexArray) {
            v.showVertex();
        }
    }
    //additional code
    void Graph::findComponents() { 
        vector<bool> explored(vertexArray.size(), false);
        int comp = 0; //component number
        
        // for each vertex, starting at 0, if it's unexplored, add to the component number
        // and perform to DFS, assigning that number to all conecnted vertices
        for (int start = 0; start < vertexArray.size(); start++) {
            if (!explored[start]) { //if node has been explore (ie, has bene assigned a new component number), ignore it
                comp++;

                //dfs
                stack<int> open;
                open.push(start);
                while (!open.empty()) {
                    int v = open.top();
                    open.pop();
            
                    if (!explored[v]) { //if the node HAS been explored, just ignore it!!!
                        explored[v] = true;
                        vertexArray[v].setComponent(comp);
                        int v2; // must declare before use in loop
                        for (auto edge : vertexArray[v].getEdges()){ //only adds edges IF it hasn't been explored previously
                            v2 = edge.getVertex2();
                            if (!explored[v2]) { open.push(v2); }
                        }
                    }          
                }
            }
        }
    };
}