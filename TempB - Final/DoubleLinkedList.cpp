#include <iostream>
#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : head(nullptr), trailer(nullptr), count(0) {}

Node* DoubleLinkedList::begin() {
    return head;
}

Node* DoubleLinkedList::end() {
    return trailer;
}

int DoubleLinkedList::size() {
    return count;
}

bool DoubleLinkedList::empty() {
    return count <= 0;
}

void DoubleLinkedList::push_front(int a) {
    Node* node = new Node(a);
    node->setNext(head);
    if (head != nullptr) {
        head->setPrev(node);
    }
    head = node;
    if (trailer == nullptr) {
        trailer = node;
    }
    count++;
}

void DoubleLinkedList::push_back(int a) {
    Node* node = new Node(a);
    if (head == nullptr) {
        head = node;
        trailer = node;
    } else {
        trailer->setNext(node);
        node->setPrev(trailer);
        trailer = node;
    }
    count++;
}

void DoubleLinkedList::printFor() {
    Node* curr = head;
    while (curr) {
        std::cout << curr->getData();
        std::cout << "->";
        curr = curr->getNext();
    }
    std::cout << "Null \n";
}

void DoubleLinkedList::printBack() {
    Node* curr = trailer;
    while (curr) {
        std::cout << curr->getData();
        std::cout << "->";
        curr = curr->getPrev();
    }
    std::cout << "Null \n";
}
