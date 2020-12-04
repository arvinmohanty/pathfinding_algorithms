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

        void dfs_helper(int NodeID, vector<bool> visited, vector<int>& path);
        
        vector<int> landmarkPath(int startNode, int landmarkID, int toGoToID); // returns an int? unsure
        
        

        int adj_list_size;

        UndirectedGraph roads;
    private:


};

