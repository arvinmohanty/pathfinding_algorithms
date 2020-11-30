#pragma once
#include "Node.h"
#include <string>
#include <fstream>
#include <vector>
using std::string;

class UndirectedGraph {
    public:
        UndirectedGraph();
        
        void load(string filename);
        ~UndirectedGraph();


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
