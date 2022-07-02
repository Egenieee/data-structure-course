//
//  main.cpp
//  Assignment4
//
//  Created by 이진희 on 2021/06/21.
//

#include <iostream>
#include <fstream>

#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int startNode;
    int targetNode;
    
    Graph<int> graph;
    
    int nodeNum;
    int edgeNum;

    ifstream file ("/Users/j2n2/USA-road-d.NY.gr.txt");
    if(file.fail()) {
        cout << "파일을 찾을 수 없음" << endl;
        exit(100);
    }
    
    file >> nodeNum >> edgeNum;
    
    for( int i = 0; i < nodeNum ; i++ ) {
        graph.addNode(i);
    }
    
    for( int i = 0; i < edgeNum ; i++ ) {
        string msg;
        int start;
        int end;
        int distance;
        
        file >> msg >> start >> end >> distance;
        
        graph.addEdge(start - 1, end - 1, distance);
    }
    
    file.close();
    
    cin >> startNode >> targetNode;
    
    vector<int> print_path = graph.SPT(startNode, targetNode);
    
    for(auto path : print_path) {
        cout << path + 1 << " ";
    }
    
    cout << endl;
    
    return 0;
}
