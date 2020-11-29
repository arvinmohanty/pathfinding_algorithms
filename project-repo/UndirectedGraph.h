#pragma once
#include "Node.h"
#include <string>
#include <fstream>
using std::string;

class UndirectedGraph {
    public:
        UndirectedGraph();
        UndirectedGraph(string filename);
        void load(string filename);
        ~UndirectedGraph();

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
