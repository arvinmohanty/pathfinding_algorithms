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
        void dfs(int NodeID);

        void dfs_helper(int NodeID, vector<bool> visited);
        
        vector<int> landmarkPath(int startNode, int landmarkID, int toGoToID); // returns an int? unsure
        // template <typename T>
        // Dstepping(Node<T>* toFind);

        int node_count;

        UndirectedGraph roads;
    private:


};

