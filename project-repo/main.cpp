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

   UndirectedGraph c("project-repo/tests/testdata1");
   Pathfinder d(c);

   /*vector<int> arv = p.dfs(1);
   for (int b : arv) std::cout << b <<std::endl;
   std::cout << std::endl;*/
 
 
   /*vector<int> connected = p.connectedComponent();
   for (int b : connected) std::cout << b <<std::endl;
   std::cout << std::endl;*/
 
   vector<int> landmark = d.landmarkPath(8, 94, 17);
   for (int c : landmark) std::cout << c << std::endl;
   std::cout << std::endl;
   

 
   /*vector<int> landmark_path = p.landmarkPath(1, 384, 1);
   for (int b : landmark_path) std::cout << b << std::endl;
   std::cout << std::endl;*/


    
    

    
}
