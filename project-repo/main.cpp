#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>

int main() {
    
    //UndirectedGraph a("roadNet-CA.txt");
    UndirectedGraph a("project-repo/tests/testdata1");
    Pathfinder p(a);

    vector<int> vect = p.shortestPath(0, 387);
    for (int i : vect) {
        std::cout << i << std::endl;
    }
    p.landmarkPath(0, 98, 0);
    
    
}