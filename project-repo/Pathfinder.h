#pragma once
#include "Node.h"
#include "UndirectedGraph.h"

class Pathfinder {
    public: 
        Pathfinder();
        Pathfinder(UndirectedGraph graph);
        
        int shortestPath(int NodeID); 

        //nodeID from starting node
        void dfs(int NodeID);

        void dfs_helper(int NodeID, vector<bool> visited);
        
        int landmarkPath(int landmarkID, int toGoToID); // returns an int? unsure
        // template <typename T>
        // Dstepping(Node<T>* toFind);

        int node_count;

        UndirectedGraph roads;
    private:


};

