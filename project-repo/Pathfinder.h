#pragma once
#include "UndirectedGraph.h"
#include <vector>
using std::vector;


/**
 * Stores all relevant algorithms to be performed on the graph
 * The algorithms relevant to the project spec are DFS, landmark path, and strongly connected component
 * Also includes shortest path which is done using a modified BFS. This is a helper function for landmark path.
*/
class Pathfinder {
    public: 
        
        // zero constructor which initializes the class
        Pathfinder();

        // initializes the class with an undirected graph object
        Pathfinder(UndirectedGraph graph);
        
        // finds the shortest path between two nodes using a modified BFS which returns a vector of the path
        // returns an empty vector if no path is found
        vector<int> shortestPath(int startNode, int endNode); 

        // NOT IMPLEMENTED!!
        vector<int> shortest_path_dfs(int NodeID, int depth);

        // uses a depth first search to return the path to a node (in a vector of ints) with NodeID
        vector<int> dfs(int NodeID);

        // helper function for the depth first search
        // takes in a node with NodeID, a vector of currently visited nodes, and a vector of the current path
        void dfs_helper(int NodeID, vector<bool>& visited, vector<int>& path);

        // finds the landmark path between three nodes
        // does this by finding the path from startnode->landmarkID, then the path from landmarkID->toGoToID in a single vector
        // returns an empty vector if no path is found
        vector<int> landmarkPath(int startNode, int landmarkID, int toGoToID); 


        //returns connected component: a maximal connected subgraph of an undirected graph
        //helper function for strongest connected component
        // returns FIRST largest connected component found if multiple are found!!
        vector<int> connectedComponent();

        //returns vector if there is a strongest connected component: all vertices are part of one graph
        //returns empty vector if there is no SCC
        vector<int> strongestConnectedComponent();

        // variable that stores the undirected graph object
        UndirectedGraph roads;
    private:


};

