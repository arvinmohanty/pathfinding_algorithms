#pragma once
#include "Node.h"
#include "UndirectedGraph.h"

class Pathfinder {
    public: 
        Pathfinder();
        Pathfinder(UndirectedGraph graph);
        
        bool shortestPath(int startNode); 

        void shortest_path_dfs(int NodeID, int depth);

        //nodeID from starting node
        void dfs(int NodeID);

        void dfs_helper(int NodeID, vector<bool> visited);
        
        bool landmarkPath(int startNode, int landmarkID, int toGoToID); // returns an int? unsure
        // template <typename T>
        // Dstepping(Node<T>* toFind);

        int node_count;

        UndirectedGraph roads;
    private:


};

