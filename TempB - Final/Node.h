#ifndef NODE_H
#define NODE_H

class Node {
    int data;
    Node* next;
    Node* prev;

public:
    Node();
    Node(int a);
    Node* getNext();
    Node* getPrev();
    void setNext(Node* b);
    void setPrev(Node* c);
    void setData(int s);
    int getData();
};

#endif // NODE_H