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


vector<int> Pathfinder::shortestPath(int startNode, int endNode) {
    if (startNode < 0 || endNode < 0 || 
        startNode > roads.adj_list_size || endNode > roads.adj_list_size
        || roads.adj_list[startNode].size() == 0 || roads.adj_list[endNode].size() == 0) return std::vector<int>();

    // predecessor vector
    vector<int> pred(roads.adj_list_size, -1);
    // path vector to return at end of function
    vector<int> pathvector;
    // queue for the breadth first search
    std::queue<int> bfs;
    // vector of booleans with each index acting as the NodeId. shows whether a node has been visited or not
    vector<bool> has_seen(roads.adj_list_size, false);
    // a vector maintaining the distance of each nodeID to the final node
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

    // if the length is 1 (meaning ONLY the end node has been pushed and there is no valid path), return an empty vector
    if (pathvector.size() <= 1) return vector<int>(); 
    
    // reverse vector as it is currently the path from end node to start node, need to instead return start node -> end node
    std::reverse(pathvector.begin(), pathvector.end());
    return pathvector; 
}


vector<int> Pathfinder::landmarkPath(int startNode, int landmarkID, int toGoToID) {
    // finding the shortest path between startNode and landmark, and also landmark to togotoID
    vector<int> pathFromStartToLandmark = shortestPath(startNode, landmarkID);
    vector<int> pathFromLandmarkToEnd = shortestPath(landmarkID, toGoToID);

    // returns an empty vector if either path is empty, meaning there is no valid path
    if (pathFromLandmarkToEnd.empty() || pathFromStartToLandmark.empty()) return vector<int>();

    // erasing the point of the landmark node as it will be duplicated
    pathFromLandmarkToEnd.erase(pathFromLandmarkToEnd.begin());

    // appending landmarktoend to starttolandmark to make a final larger vector with both paths
    pathFromStartToLandmark.insert(pathFromStartToLandmark.end(), pathFromLandmarkToEnd.begin(), pathFromLandmarkToEnd.end());
    // returning final vector
    return pathFromStartToLandmark;
}

vector<int> Pathfinder::dfs(int NodeID) {
    if (NodeID < 0 || NodeID > (roads.adj_list_size - 1)) return vector<int>();

    // vector of visited nodes with index representing node IDs
    std::vector<bool> visited(roads.adj_list_size, false);
    // vector of the current path
    std::vector<int> path;

    // call to DFS helper which will fill the path vector
    dfs_helper(NodeID, visited, path);

    return path;
}

void Pathfinder::dfs_helper(int NodeID, std::vector<bool>& visited, vector<int>& path) {
    // current node has just been visited
    visited[NodeID] = true;
    path.push_back(NodeID);

    //each int i corresponds to a nodeID
    for (int i : roads.adj_list[NodeID]) {

        // recursive call onto the next unvisited node
        if (!visited[i]) dfs_helper(i, visited, path);
    }
}

vector<int> Pathfinder::connectedComponent() {
    //using dfs - similar vector of visited nodes like the one above
    std::vector<bool> has_seen(roads.adj_list.size(), false);

    // vector containing the nodes in the connected component
    vector<int> connectedComponent;

    for (int i = 0; i < (int) roads.adj_list.size(); i++) {
        // every time the adj matrix is loaded, the size is based on the largest value
        // however we may not be looking at the entire file (testing in snippets)
        // hence we need to check if roads.adj_list[i].size() > 0, in order to make sure the vertex exists
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

    // similar to the code above:
    // every time the adj matrix is loaded, the size is based on the largest value
    // however we may not be looking at the entire file (testing in snippets)
    // hence we need to check if roads.adj_list[i].size() > 0, in order to make sure the vertex exists
    // we only add to existing vertices if this is the case 
    for (std::set<int> a : roads.adj_list) {
        if (a.size() > 0) existing_vertices++;
    }

    vector<int> connected = connectedComponent();
    // returns the connected component with the value of existing vertices (hence the strongest component)
    if ((int) connected.size() == existing_vertices) {
        return connected;
    } 

    // returns an empty vector if that does not exist    
    return vector<int>();
}
