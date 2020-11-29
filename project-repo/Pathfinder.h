#pragma once
#include "Node.h"
#include "UndirectedGraph.h"

class Pathfinder {
    public: 
        Pathfinder();
        Pathfinder(UndirectedGraph* graph);
        template <typename T>
        int shortestPath(Node<T>* toFind); 
        template <typename T>
        int landmarkPath(Node<T>* landmark, Node<T> toGoTo); // returns an int? unsure
        // template <typename T>
        // Dstepping(Node<T>* toFind);
    private:


};
