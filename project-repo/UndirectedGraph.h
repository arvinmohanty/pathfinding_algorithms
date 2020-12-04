#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <set>
using std::string;

//A road network of California. Intersections and endpoints are represented by nodes and 
//the roads connecting these intersections or road endpoints are represented by undirected edges.



class UndirectedGraph {
    public:
        UndirectedGraph();
        
        void load(string filename);
        ~UndirectedGraph();

        int adj_list_size;

        int edge_count = 0;


        UndirectedGraph(string filename);

        //changed to sets to avoid repeats in testing issue

        // std::vector<std::vector<int>> adj_list;
        
        std::vector<std::set<int>> adj_list;



        void addEdge(int start, int end);
    private:
        

};
