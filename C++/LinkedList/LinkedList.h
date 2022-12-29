#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.h"
template<typename T> class LinkedList {
    ListNode<T>* m_head;
    ListNode<T>* m_tail;
    int m_length;
public:
    LinkedList() : 
        m_head(nullptr), m_tail(nullptr), m_length(0) {}

    ~LinkedList() {
        if(m_head) {
            ListNode<T>* tmp = m_head;
            while(tmp) {
                ListNode<T>* tmp1 = tmp;
                tmp = tmp1->next();
                delete tmp1;
            }
        }
    }
      

    void pushBack(T val) {
        if (m_head && m_tail) {
            m_tail->setNext(new ListNode<T>(val));
            m_tail = m_tail->next();
        } else {
            m_head = new ListNode<T>(val);
            m_tail = m_head;
        }
        ++m_length;
    }
    void pushFront(T val) {
        if (m_head && m_tail) {
            ListNode<T>* tmp = new ListNode<T>(val);
            tmp->setNext(m_head);
            m_head = tmp;
        } else {
            m_head = new ListNode<T>(val);
            m_tail = m_head;
        }
        ++m_length;
    }

    T get(int index=0) {
        if (index >= m_length) return m_tail->get();
        int i = 0;
        ListNode<T>* tmp;
        tmp = m_head;
        while(i < index) {
            tmp = tmp->next();
            ++i;
        }
        return tmp->get();
    }
    ListNode<T>* head() { return &m_head; }
    ListNode<T>* tail() { return &m_tail; }
};
#endif