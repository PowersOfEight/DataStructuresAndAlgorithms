#ifndef TREENODE_H
#define TREENODE_H
#include "../Node/Node.h"
#include <iostream>
template<typename T> class TreeNode : 
    public Node<T> {
        TreeNode<T>* m_left;
        TreeNode<T>* m_right;
public:
    TreeNode(T val) : 
        Node<T>(val), m_left(nullptr), m_right(nullptr) {}

    void setLeft(TreeNode<T>* left) { this->m_left = left; }
    void setRight(TreeNode<T>* right) { this->m_right = right; }
    TreeNode<T>* left() const { return m_left; }
    TreeNode<T>* right() const { return m_right; }
};
#endif