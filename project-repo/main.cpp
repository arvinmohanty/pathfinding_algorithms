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
    vector<int> landmark = p.landmarkPath(0, 98, 0);
    for (int i : landmark) {
        std::cout << i << std::endl;
    }
    
}