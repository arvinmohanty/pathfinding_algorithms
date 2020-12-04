#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>
#include <vector>

int main() {
    
    //UndirectedGraph a("roadNet-CA.txt");
    UndirectedGraph a("project-repo/tests/testdata1");
    Pathfinder p(a);

    std::vector<int> arv = p.dfs(1);
    

    
}