#pragma once
#include <vector>
using std::vector;

template <class T>

class Node {
    public:
        Node();
        Node(const T & mdata);
        ~Node();
        const T data;
        vector<Node<T>*> edges;

    private:


};
