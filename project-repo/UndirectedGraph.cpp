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
    node_count = max + 1;
    adj_list.resize(node_count, vector<int>());

    //reset ifstream to beginning or file to be reread and edges made
    file.clear();
    file.seekg(0);

    while(getline(file, arv)) {
        
        if (arv[0] == '#') continue;
    
        std::stringstream split(arv);
        int start;
        int end;

        split >> start >> end;
        //std::cout << start << " " << end << std::endl;

        addEdge(start, end);
        
    }


    //in undirected graphs, only count edges from distinct vertices once
    edge_count /= 2;
    
    




}

void UndirectedGraph::load(string filename) {

}

UndirectedGraph::~UndirectedGraph() {

}

void UndirectedGraph::addEdge(int start, int end) {
    //edge going from start to end, and end to start, since dataset is undirected according to stanford snap
    adj_list[start].push_back(end);

    edge_count++;

    //would normally do this step since undirected graph, but dataset represents starts/ends:
    //adj_list[end].push_back(start);
    //e.g. if 1 -> 5, 5 -> 1 will also be present
    //dont want repeats
    



}
