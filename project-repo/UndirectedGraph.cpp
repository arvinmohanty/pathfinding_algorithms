#include "UndirectedGraph.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
UndirectedGraph::UndirectedGraph() {
  
}

UndirectedGraph::UndirectedGraph(string filename) {

    //reading file into graph represented by adj_matrix
    //, adjusting size of adj_matrix, and creating edges

    std::string arv;
    std::ifstream file(filename);
    int count = 0;
    
    int max = INT_MIN;

    while(!file.eof()) {
        
        getline(file, arv);

        if (arv[0] == '#') continue;

    

    
        std::stringstream split(arv);
        int start;
        int end;

        split >> start;
        split >> end;

        max = std::max(max, std::max(start, end));


        //need to add 1 because of basic vector size rules

        //linear time

        std::cout << start << " " << end << std::endl;

        adj_matrix.resize(max + 1, vector<int> (max + 1, 0));

        addEdge(start, end);

        
        count++;
    }


}

void UndirectedGraph::load(string filename) {

}

UndirectedGraph::~UndirectedGraph() {

}

void UndirectedGraph::addEdge(int start, int end) {
    //edge going from start to end

    



}
