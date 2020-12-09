#include "UndirectedGraph.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
UndirectedGraph::UndirectedGraph() {
  
}

UndirectedGraph::UndirectedGraph(string filename) {
    load(filename);
}

void UndirectedGraph::load(string filename) {
    //adjacency matrix wont work because of space constraints, ud have a matrix with 1.9 million
    //rows each with 1.9 million
    //adjacency list works since the road network is sparse, intuition: roads in one place dont connect to roads
    //in a completely different place (not all the others), so each inner vector will be smaller than 1.9 million

    std::string arv;
    std::ifstream file(filename);
    
    
    int max = INT_MIN;

    //two pass approach, first to find highest node id (tells us how many nodes there could maximally be), 
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
    adj_list_size = max + 1;
    
    adj_list.resize(adj_list_size, std::set<int>());

    //reset ifstream to beginning or file to be reread and edges made
    file.clear();
    file.seekg(0);

    while(getline(file, arv)) {
        
        if (arv[0] == '#') continue;
    
        std::stringstream split(arv);
        int start;
        int end;

        split >> start >> end;

        addEdge(start, end);
        
    }


    //in undirected graphs, only count edges from distinct vertices once
    edge_count /= 2;
}

UndirectedGraph::~UndirectedGraph() {

}

void UndirectedGraph::addEdge(int start, int end) {
    //edge going from start to end, and end to start, since dataset is undirected according to stanford snap
    //if 0 -> 1, dataset will have another line where 1->0, since it shows each to from relationship, and since its undirected, there must be this pattern
    //but in testing where we use a truncated txt file, we may miss one of the edgessince it is lower or higher in the file (which is problematic since
    //undirected graphs are directed graphs that have double facing edges)

    //therefore we add both, and we change adjacency list to be a vector of sets instead of vector or vectors to avoid repeats, this cleaned up some edge cases

    adj_list[start].insert(end);
    adj_list[end].insert(start);


    edge_count++;
}
