
#ifndef DISJOINTSETS_NODE_H
#define DISJOINTSETS_NODE_H

class Node {
public:
    int data;
    Node* parent=nullptr;
    int rank=0;
    int children=0;
    Node(int d) {
        this->data = d;
        this->parent=this;
    };
};

#endif //DISJOINTSETS_NODE_H
