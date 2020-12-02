#include "Node.h"
#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>

int main() {
    
    //UndirectedGraph a("roadNet-CA.txt");
    UndirectedGraph a("project-repo/test");
    Pathfinder p(a);
    
    p.shortestPath(0);
}