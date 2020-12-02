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


bool Pathfinder::shortestPath(int startNode, int endNode) {

    
    std::queue<int> bfs;

    vector<bool> has_seen(roads.node_count, false);
    vector<int> dist(roads.node_count);
    
    //starting at start node
    has_seen[startNode] = true;
    dist[startNode] = 0;

    bfs.push(startNode);

    while (!bfs.empty()) {
        int front = bfs.front();
	    bfs.pop();

        //i is each node id
        for (auto i : roads.adj_list[front]) {

            if (has_seen[i] == false) {
                has_seen[i] = true;
                dist[i] = dist[front] + 1;


                //have reached endNode
                
                if (i == endNode) {
                    std::cout << dist[i];
                    return true;
                }
                
                bfs.push(i);
                //pushing back for later bfs on this node
            }
        }

    }

    std::cout << "no path";

    return false;


}


bool Pathfinder::landmarkPath(int startNode, int landmarkID, int toGoToID) {
    bool pathFromStartToLandmark = shortestPath(startNode, landmarkID);
    bool pathFromLandmarkToEnd = shortestPath(landmarkID, toGoToID);

    return pathFromStartToLandmark && pathFromLandmarkToEnd;
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



