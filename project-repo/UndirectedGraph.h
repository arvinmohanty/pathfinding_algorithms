#pragma once
#include "Node.h"
#include <string>
#include <fstream>
#include <vector>
using std::string;

//A road network of California. Intersections and endpoints are represented by nodes and 
//the roads connecting these intersections or road endpoints are represented by undirected edges.



class UndirectedGraph {
    public:
        UndirectedGraph();
        
        void load(string filename);
        ~UndirectedGraph();

        int node_count;

        int edge_count = 0;


        UndirectedGraph(string filename);


        std::vector<std::vector<int>> adj_list;

        void addEdge(int start, int end);


        class DFS_iterator {
            public:
            // begin()
            // end()
            // operator ++
            // operator -- (optional)
            // operator*
            // operator !=


            
            private:

        };
        
    private:
        

};
