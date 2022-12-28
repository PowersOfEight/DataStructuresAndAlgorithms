#ifndef LISTNODE_H
#define LISTNODE_H
#include "../Node/Node.h"
template<typename T> class ListNode :
    public Node<T> {
    
    Node<T>* m_next;
    
public:
    ListNode() : Node<T>(0), m_next(nullptr) {}

    ListNode(T val) : Node<T>(val), m_next(nullptr) {}

    ListNode(T val, Node<T>* next) : Node<T>(val), m_next(next) {}

    Node<T>* next() { return m_next; }

    void setNext(Node<T>* nxt) { m_next = nxt; }
};
#endif