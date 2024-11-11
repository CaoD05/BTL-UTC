#include "Node.h"

Node::Node() : data(0), next(nullptr), prev(nullptr) {}

Node::Node(int a) : data(a), next(nullptr), prev(nullptr) {}

Node* Node::getNext() {
    return next;
}

Node* Node::getPrev() {
    return prev;
}

void Node::setNext(Node* b) {
    next = b;
}

void Node::setPrev(Node* c) {
    prev = c;
}

void Node::setData(int s) {
    data = s;
}

int Node::getData() {
    return data;
}
