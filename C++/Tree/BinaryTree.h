#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "TreeNode.h"
#include <functional>
template<typename T, class Compare = std::less<T>>
class BinaryTree {
    Compare m_compare;
    TreeNode<T>* m_root;
    size_t m_size;
public:
    BinaryTree() :
        m_root(nullptr), m_compare(Compare<T>()), m_size(0) {}
    ~BinaryTree() {
        delete m_root;
    } 
    
};
#endif