#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>
#include <vector>

int main() {
    
    //UndirectedGraph a("roadNet-CA.txt");
    UndirectedGraph a("project-repo/tests/testdata1");
    Pathfinder p(a);

    vector<int> arv = p.dfs(1);
    for (int b : arv) std::cout << b <<std::endl;
    // std::cout << arv.size();
    // vector<int> arvi = p.dfs(1);
    // for (int i : arvi) std::cout << i;



 

    // std::vector<int> arv = p.connectedComponent();
    // for (int i : arv) std::cout << i;


    

    
    

    
}