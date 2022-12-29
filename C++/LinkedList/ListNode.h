#ifndef LISTNODE_H
#define LISTNODE_H
#include "../Node/Node.h"
#include <iostream>
template<typename T> class ListNode :
    public Node<T> {
    
    ListNode<T>* m_next;
    
public:
    ListNode() : Node<T>(0), m_next(nullptr) {}
    ~ListNode() {
        std::cerr << "Deleting node: " << this->get() << "\n";
    }
    ListNode(T val) : Node<T>(val), m_next(nullptr) {}

    ListNode(T val, ListNode<T>* next) : Node<T>(val), m_next(next) {}

    ListNode<T>* next() { return m_next; }

    void setNext(ListNode<T>* nxt) { m_next = nxt; }
};
#endif