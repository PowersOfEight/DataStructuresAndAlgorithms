#ifndef TREENODE_H
#define TREENODE_H
#include "../Node/Node.h"
using namespace std;

template<typename T> class TreeNode : 
    public Node<T> {
        TreeNode<T>* m_left;
        TreeNode<T>* m_right;
public:
    TreeNode(T val) : 
        Node<T>(val), m_left(nullptr), m_right(nullptr) {}
    ~TreeNode() {
        if (m_left){
            delete m_left;
        } 
        if (m_right){
            delete m_right;
        }
    }
    void setLeft(TreeNode<T>* left) { 
        if(m_left) m_left->~TreeNode();
        this->m_left = left;
    }
    void setRight(TreeNode<T>* right) { 
        if(m_right) m_right->~TreeNode();
        this->m_right = right; 
    }
    TreeNode<T>* left() const { return m_left; }
    TreeNode<T>* right() const { return m_right; }
};
#endif