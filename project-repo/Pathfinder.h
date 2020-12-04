#pragma once
#include "UndirectedGraph.h"
#include <vector>
using std::vector;

class Pathfinder {
    public: 
        
        Pathfinder();
        Pathfinder(UndirectedGraph graph);
        
        vector<int> shortestPath(int startNode, int endNode); 

        void shortest_path_dfs(int NodeID, int depth);

        //nodeID from starting node
        vector<int> dfs(int NodeID);

        void dfs_helper(int NodeID, vector<bool>& visited, vector<int>& path);
        
        vector<int> landmarkPath(int startNode, int landmarkID, int toGoToID); // returns an int? unsure


        //returns connected component: a maximal connected subgraph of an undirected graph
        //helper function for strongest connected component
        vector<int> connectedComponent();

        //returns vector if there is a strongest connected component: all vertices are part of one graph
        //returns empty vector if there is no SCC
        vector<int> strongestConnectedComponent();


        
        

        

        UndirectedGraph roads;
    private:


};

