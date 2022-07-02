//
//  Graph.hpp
//  Assignment4
//
//  Created by 이진희 on 2021/06/21.
//

#ifndef Graph_hpp
#define Graph_hpp


#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

template<typename T>
struct Graph{
    vector<vector<pair<int, int>>> adjList;
    vector<T> nodes;
    
    void addNode( const T& t) {
        nodes.push_back(t);
        adjList.resize(nodes.size());
    }
    
    void addEdge( int from, int to, int weight) {
        adjList[from].push_back({to, weight});
//        adjList[to].push_back({from, weight});
    }
    
    void addEdges( int from, const vector<pair<int, int>>& to_s) {
        for( auto to : to_s ) {
            addEdge(from, to.first, to.second);
        }
    }
    
    struct NodeInfo {
        int node;
        int dist;
    };

    struct NodeCompare {
        bool operator() ( const NodeInfo & I, const NodeInfo & r ) {
            return I.dist > r.dist;
        }
    };

    vector<int> SPT(int startNode, int targetNode) {
        vector<bool> visited(nodes.size(), false);
        vector<int> parent( nodes.size(), -1);
        vector<int> distance ( nodes.size(), numeric_limits<int>::max());
        priority_queue<NodeInfo, vector<NodeInfo>, NodeCompare> queue;
        vector<T> print_path;
        
        startNode = startNode - 1;
        targetNode = targetNode - 1;
        
        distance[startNode] = 0;
        queue.push( {startNode, 0} );
        
        while( !queue.empty() ) {
            auto [theNode, weight] = queue.top();
            queue.pop();
            if ( !visited[theNode] ) {
                visited[theNode] = true;
                if( theNode == targetNode ) {
                    break;
                }
                for (auto [dstNode,EdgeDist] : adjList[theNode]) {
                    if( distance[dstNode] > distance[theNode] + EdgeDist ) {
                        distance[dstNode] = distance[theNode] + EdgeDist;
                        parent[dstNode] = theNode;
                        queue.push( { dstNode, distance[dstNode] } );
                    }
                }
            }
        }
        
        int currentNode = targetNode;
        
        while ( currentNode != startNode ) {
            print_path.push_back( currentNode );
            currentNode = parent[currentNode];
        }
        print_path.push_back(startNode);
        
        reverse(print_path.begin(), print_path.end());
        
        return print_path;
    }
    
};




#endif /* Graph_hpp */
