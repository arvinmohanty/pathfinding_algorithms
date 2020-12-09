#include "Pathfinder.h"
#include "UndirectedGraph.h"
#include <iostream>
#include <vector>

int main() {

   //functionality of DFS, SCC, and Landmark path: prints out each path/traversal one vertice at a time
    
   UndirectedGraph a("project-repo/tests/testdata1");
   Pathfinder p(a);


   vector<int> dfs_path = p.dfs(1);
   for (int v : dfs_path) std::cout << v << std::endl;
   std::cout << std::endl;


   vector<int> landmark_path = p.landmarkPath(1, 384, 1);
   for (int v : landmark_path) std::cout << v << std::endl;
   std::cout << std::endl;
 
 
   vector<int> connected = p.connectedComponent();
   for (int v : connected) std::cout << v <<std::endl;
   std::cout << std::endl;


   //implementing with a dataset that actually has an SCC, since otherwise we handled for the edge case where there is no SCC
   //and returns an empty vector
   //that wouldn't show us anything in that case

   UndirectedGraph SCC_graph("project-repo/tests/testdataSCC2.txt");
   Pathfinder SCC(SCC_graph);

   
   vector<int> SCC_path = SCC.strongestConnectedComponent();
   for (int v : SCC_path) std::cout << v << std::endl;
   std::cout << std::endl;
   

 



    
    

    
}
