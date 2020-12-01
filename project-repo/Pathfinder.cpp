#include "Pathfinder.h"
#include <iostream>

Pathfinder::Pathfinder() {
  
}

Pathfinder::Pathfinder(UndirectedGraph graph) {

    roads = graph;
}

int Pathfinder::shortestPath(int NodeID) {
    return 0;

}


int Pathfinder::landmarkPath(int landmarkID, int toGoToID) {
    return 0;
}

void Pathfinder::dfs(int NodeID) {
    std::vector<bool> visited(roads.node_count, false);
    dfs_helper(NodeID, visited);

}

//dfs
void Pathfinder::dfs_helper(int NodeID, std::vector<bool> visited) {
    
    visited[NodeID] = true;
    std::cout << NodeID;
    //adj_list[NodeID]

    //each int i corresponds to a nodeID
    for (int i : roads.adj_list[NodeID]) {
        if (!visited[i]) dfs_helper(i, visited);
    }



}



