#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() : 
    m_head(nullptr), m_tail(nullptr), m_length(0) {}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    
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

template<typename T>
LinkedList<T>::~LinkedList() {
    if(m_head) {
        ListNode<T>* ptr = m_head;
        while(ptr) {
            ListNode<T>* tmp = ptr;
            ptr = tmp->next();
            delete tmp;
        }
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
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
    if (other.head()) {
        ListNode<T>* currentOther = other.head();
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

template<typename T>
T LinkedList<T>::get(int index) {
    if (m_length == 0 || index >= m_length || index < 0) 
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

template<typename T>
size_t LinkedList<T>::size() const { return m_length; }

template<typename T>
ListNode<T>* LinkedList<T>::head() const { return m_head; }

template<typename T>
ListNode<T>* LinkedList<T>::tail() const { return m_tail; }

template<typename T>
void LinkedList<T>::pushBack(T val) {
    if (m_head && m_tail) {
        m_tail->setNext(new ListNode<T>(val));
        m_tail = m_tail->next();
    } else {
        m_head = new ListNode<T>(val);
        m_tail = m_head;
    }
    ++m_length;
}

template<typename T>
void LinkedList<T>::pushFront(T val) {
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

template class LinkedList<int>;