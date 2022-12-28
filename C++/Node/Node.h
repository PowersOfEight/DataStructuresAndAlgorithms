#ifndef NODE_H
#define NODE_H
/**
 * This is the parent class for any node in a node-based
 * data structure.  Any node-based data structure will have
 * some type of value associated with each node.
*/
template<typename T> class Node{
    T m_value;

public:
    Node<T>(T val) : m_value(val){} 

    T get() { return this->m_value; }
    void set(T val){
        m_value = val;
    } 
};
#endif