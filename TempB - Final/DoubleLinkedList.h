#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.cpp"

class DoubleLinkedList {
private:
    Node* head;
    Node* trailer;

public:
    int count;

    Node* begin();
    Node* end();
    int size();
    bool empty();
    
    DoubleLinkedList();
    void push_front(int a);
    void push_back(int a);
    void printFor();
    void printBack();
};

#endif // DOUBLELINKEDLIST_H
