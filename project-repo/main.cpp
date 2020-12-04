#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>
#include <vector>

int main() {
    
    UndirectedGraph a("project-repo/tests/testdata2.txt");
   Pathfinder p(a);
 //first dataset

   vector<int> arv = p.dfs(1);
   for (int b : arv) std::cout << b <<std::endl;
   std::cout << std::endl;
 
 
   vector<int> connected = p.connectedComponent();
   for (int b : connected) std::cout << b <<std::endl;
   std::cout << std::endl;
 
   vector<int> shortestPath = p.shortestPath(1, 384);
   for (int b : shortestPath) std::cout << b << std::endl;
   std::cout << std::endl;
 
   vector<int> landmark_path = p.landmarkPath(1, 384, 1);
   for (int b : landmark_path) std::cout << b << std::endl;
   std::cout << std::endl;


    
    

    
}