#include "Node.h"
#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>

int main() {
    
    //UndirectedGraph a("roadNet-CA.txt");
    UndirectedGraph a("project-repo/tests/testdata1");
    Pathfinder p(a);
    p.shortestPath(0, 387);
    p.landmarkPath(0, 98, 0);
    
    
}