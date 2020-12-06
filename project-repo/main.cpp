#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>
#include <vector>

int main() {
    
   UndirectedGraph a("project-repo/tests/testdata2.txt");
   Pathfinder p(a);
   UndirectedGraph b;
   b.load("project-repo/tests/testdata2.txt");
   Pathfinder p2(b);

   /*vector<int> arv = p.dfs(1);
   for (int b : arv) std::cout << b <<std::endl;
   std::cout << std::endl;*/
 
 
   /*vector<int> connected = p.connectedComponent();
   for (int b : connected) std::cout << b <<std::endl;
   std::cout << std::endl;*/
 
   vector<int> shortestPath = p.shortestPath(40, 44);
   for (int c : shortestPath) std::cout << c << std::endl;
   std::cout << std::endl;
   

   vector<int> shortestPath2 = p2.shortestPath(40, 44);
   for (int c : shortestPath2) std::cout << c << std::endl;
   std::cout << std::endl;

 
   /*vector<int> landmark_path = p.landmarkPath(1, 384, 1);
   for (int b : landmark_path) std::cout << b << std::endl;
   std::cout << std::endl;*/


    
    

    
}