#include "UndirectedGraph.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
UndirectedGraph::UndirectedGraph() {
  
}

UndirectedGraph::UndirectedGraph(string filename) {

    //adjacency matrix wont work because of space constraints, ud have a matrix with 1.9 million
    //rows each with 1.9 million
    //adjacency list works since the road network is sparse, intuition: roads in one place dont connect to roads
    //in a completely different place, so each inner vector will be smaller than 1.9 million

    std::string arv;
    std::ifstream file(filename);
    
    
    int max = INT_MIN;

    //two pass approach, first to find highest node id (tells us how many nodes there are), 
    //second to put edges into adjacency list
    //need highest node since nodes are named starting from 0

    while(getline(file, arv)) {
        
        if (arv[0] == '#') continue;
    
        std::stringstream split(arv);
        int start;
        int end;

        split >> start >> end;

        max = std::max(max, std::max(start, end));
        
    }

    //need to add 1 to size so we can actually index last node
    adj_list.resize(max + 1, vector<int>());

    while(getline(file, arv)) {
        
        if (arv[0] == '#') continue;
    
        std::stringstream split(arv);
        int start;
        int end;

        split >> start >> end;

        addEdge(start, end);
        
    }




}

void UndirectedGraph::load(string filename) {

}

UndirectedGraph::~UndirectedGraph() {

}

void UndirectedGraph::addEdge(int start, int end) {
    //edge going from start to end
    adj_list[start].push_back(end);

}
