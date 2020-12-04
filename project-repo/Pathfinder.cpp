#include "Pathfinder.h"
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>

using std::vector;

Pathfinder::Pathfinder() {
  
}

Pathfinder::Pathfinder(UndirectedGraph graph) {

    roads = graph;
}

//if path does not exist, return false
//using bfs and recording distance of each node visited from start node

vector<int> Pathfinder::shortestPath(int startNode, int endNode) {

    // predecessor vector
    vector<int> pred(roads.adj_list_size, -1);
    // path vector to return at end of function
    vector<int> pathvector;
    
    std::queue<int> bfs;

    vector<bool> has_seen(roads.adj_list_size, false);
    vector<int> dist(roads.adj_list_size);
    
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
                // predecessor of node id is the node at the front of queue / the IOP node
                pred[i] = front;

                //have reached endNode
                
                if (i == endNode) {
                    //std::cout << dist[i];
                    //return true;
                    break; // breaking as end node is reached
                }
                
                bfs.push(i);
                //pushing back for later bfs on this node
            }
        }

    }

    int dest = endNode; // copying value for end node as it will be modified
    // pushing back end node
    pathvector.push_back(dest);
    while(pred[dest] != -1) { // while there is a valid predecessor
        pathvector.push_back(pred[dest]); // pushes back all predecessors into the path vector
        dest = pred[dest]; // sets new predecessor
    }
    if (pathvector.size() <= 1) return vector<int>(); // if the length is 1 (meaning ONLY the end node has been pushed), return an empty vector
    //std::cout << "no path";
    //return false;
    std::reverse(pathvector.begin(), pathvector.end());
    return pathvector; // otherwise return path vector
}


vector<int> Pathfinder::landmarkPath(int startNode, int landmarkID, int toGoToID) {
    vector<int> pathFromStartToLandmark = shortestPath(startNode, landmarkID);
    vector<int> pathFromLandmarkToEnd = shortestPath(landmarkID, toGoToID);
    // appending landmarktoend to starttolandmark to make a final larger vector with both paths
    pathFromLandmarkToEnd.erase(pathFromLandmarkToEnd.begin());
    pathFromStartToLandmark.insert(pathFromStartToLandmark.end(), pathFromLandmarkToEnd.begin(), pathFromLandmarkToEnd.end());
    // returning final vector
    return pathFromStartToLandmark;
}

vector<int> Pathfinder::dfs(int NodeID) {
    std::vector<bool> visited(roads.adj_list_size, false);
    std::vector<int> path;
    dfs_helper(NodeID, visited, path);

    return path;

}

// void Pathfinder::dfs_helper(int NodeID, std::vector<bool> visited) {

//      visited[NodeID] = true;
//     std::cout << NodeID;
//      //adj_list[NodeID]

//      //each int i corresponds to a nodeID
//      for (int i : roads.adj_list[NodeID]) {
//          if (!visited[i]) dfs_helper(i, visited);
//      }



//  }

//dfs complete
void Pathfinder::dfs_helper(int NodeID, std::vector<bool>& visited, vector<int>& path) {
    
    visited[NodeID] = true;
    path.push_back(NodeID);
    // std::cout << NodeID;

    //each int i corresponds to a nodeID
    for (int i : roads.adj_list[NodeID]) {
        if (!visited[i]) dfs_helper(i, visited, path);
    }
}

vector<int> Pathfinder::connectedComponent() {
    //using dfs
    
    std::vector<bool> has_seen(roads.adj_list.size(), false);
    vector<int> connectedComponent;

    

    for (int i = 0; i < roads.adj_list.size(); i++) {
        //everytime u load in adj matrix, u create the size based upon the largest value,
        //but u may not be looking at the entire file, so need to check if roads.adj_list[i].size() > 0,
        //to make sure that vertex exists
        if (roads.adj_list[i].size() > 0 && !has_seen[i]) {
            vector<int> path;
            
            dfs_helper(i, has_seen, path);

            if (path.size() > connectedComponent.size()) connectedComponent = path;
        }
    }

    

    return connectedComponent;
}

vector<int> Pathfinder::strongestConnectedComponent() {
    int existing_vertices = 0;

    //this step is necessary since (comment above is same)
    //everytime u load in adj matrix, u create the size based upon the largest value,
    //but u may not be looking at the entire file, b

    //hence u now make sure that u have the appropriate amount of vertices w existing_vertices
    
    for (std::set<int> a : roads.adj_list) {
        if (a.size() > 0) existing_vertices++;
    }

    
    vector<int> connected = connectedComponent();
    if (connected.size() == existing_vertices) {
        return connected;
    } 
        
    return vector<int>();



}



