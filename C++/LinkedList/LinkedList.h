#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.h"
#include <stdexcept>
template<typename T> class LinkedList {
    ListNode<T>* m_head;
    ListNode<T>* m_tail;
    size_t m_length;
public:
    LinkedList() : 
        m_head(nullptr), m_tail(nullptr), m_length(0) {}

    LinkedList(const LinkedList<T>& other){
        if (other.size() == 0) {
            m_head = nullptr;
            m_tail = nullptr;
            m_length = 0;
        } else {
            ListNode<T>* currentOther = other.head();
            m_head = (new ListNode<T>(currentOther->get()));
            ListNode<T>* currentThis = m_head;
            while(currentOther->next()) {
                currentOther = currentOther->next();
                currentThis->setNext(
                    new ListNode<T>(currentOther->get()));
                currentThis = currentThis->next();
            }
            m_tail = currentThis;
            m_length = other.size();
        }
    }

    ~LinkedList() {
        if(m_head) {
            ListNode<T>* ptr = m_head;
            while(ptr) {
                ListNode<T>* tmp = ptr;
                ptr = tmp->next();
                delete tmp;
            }
        }
    }
      
    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) return *this;

        if (m_head) {
            ListNode<T>* ptr = m_head;
            while(ptr) {
                ListNode<T>* tmp = ptr;
                ptr = tmp->next();
                delete tmp;
            }
            m_head = nullptr;
            m_tail = nullptr;
            m_length = 0;
        }

        if (other->head()) {
            ListNode<T>* currentOther = other->head();
            m_head = new ListNode<T>(currentOther->get());
            ListNode<T>* currentThis = m_head;
            while (currentOther->next()) {
                currentOther = currentOther->next();
                currentThis->setNext(
                    new ListNode<T>(currentOther->get()));
                currentThis = currentThis->next();
            }
            m_tail = currentThis;
            m_length = other.size();
        } else {
            m_head = nullptr;
            m_tail = nullptr;
            m_length = 0;
        }

        return *this;
    }

    T get(int index=0) {
        if (m_length == 0 || index >= m_length) 
            throw std::out_of_range("Index out of range of list object");
        int i = 0;
        ListNode<T>* tmp;
        tmp = m_head;
        while(i < index) {
            tmp = tmp->next();
            ++i;
        }
        return tmp->get();
    }
    size_t size() { return m_length; }
    ListNode<T>* head() { return m_head; }
    ListNode<T>* tail() { return m_tail; }

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
};
#endif