#include "Pathfinder.h"
#include <iostream>
#include <queue>
#include <map>

Pathfinder::Pathfinder() {
  
}

Pathfinder::Pathfinder(UndirectedGraph graph) {

    roads = graph;
}

//if path does not exist, return false
//using bfs and recording distance of each node visited from start node

//too slow
bool Pathfinder::shortestPath(int startNode) {
    int V = roads.node_count; 
    int E = roads.edge_count;
    
    int dist[V]; 
  
    
    for (int i = 0; i < V; i++) dist[i] = INT_MAX; 

    dist[startNode] = 0; 
  
    
    for (int i = 1; i <= V - 1; i++) { 
        //iterating thru all the edges
        for (int j = 0; j < roads.adj_list.size(); j++) { 
            for (int k = 0; k < roads.adj_list[j].size(); k++) {
                //wont go over nodes with no edges


                int start = j;
                int end = k;

                if (dist[start] != INT_MAX) dist[end] = dist[start] + 1;
            
            }
        } 
    } 

    std::cout << dist[1];
  
    return 0;

}

void Pathfinder::shortest_path_dfs(int NodeID, int depth) {
    



}


bool Pathfinder::landmarkPath(int startNode, int landmarkID, int toGoToID) {
    // bool pathFromStartToLandmark = shortestPath(startNode, landmarkID);
    // bool pathFromLandmarkToEnd = shortestPath(landmarkID, toGoToID);

    // return pathFromStartToLandmark && pathFromLandmarkToEnd;

    return false;
}

void Pathfinder::dfs(int NodeID) {
    std::vector<bool> visited(roads.node_count, false);
    dfs_helper(NodeID, visited);

}

//dfs complete
void Pathfinder::dfs_helper(int NodeID, std::vector<bool> visited) {
    
    visited[NodeID] = true;
    // std::cout << NodeID;

    //each int i corresponds to a nodeID
    for (int i : roads.adj_list[NodeID]) {
        if (!visited[i]) dfs_helper(i, visited);
    }



}



