#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph() {
  
}

UndirectedGraph::UndirectedGraph(string filename) {
    string arv;
    std::ifstream file(filename);
    while(!file.eof()) {
        file >> arv;
        //cout << arv;




    }



}

void UndirectedGraph::load(string filename) {

}

UndirectedGraph::~UndirectedGraph() {

}
