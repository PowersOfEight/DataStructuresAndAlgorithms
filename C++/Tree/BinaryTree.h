#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "TreeNode.h"
#include <functional>
#include <vector>
template<typename T, class Compare = std::less<T> >
class BinaryTree {
    Compare m_compare;
    TreeNode<T>* m_root;
    size_t m_size;
    void insert(T value, TreeNode<T>* current) {
        if(m_compare(value, current->get())) {
            if (current->left()) {
                insert(value, current->left());
            } else {
                current->setLeft(new TreeNode<T>(value));
            }
        } else {
            if (current->right()) {
                insert(value, current->right());
            } else {
                current->setRight(new TreeNode<T>(value));
            }
        }
    }
    void vectorRecurse(std::vector<T>& vec, TreeNode<T>* current) {
        if (!current) return;
        vectorRecurse(vec, current->left());
        vec.push_back(current->get());
        vectorRecurse(vec, current->right());
    }
public:
    BinaryTree() :
        m_root(nullptr), m_compare(Compare()), m_size(0) {}
    ~BinaryTree() {
        delete m_root;
    } 
    void insert(T value) {
        if(m_root) {
            insert(value, m_root);
        } else {
            m_root = new TreeNode<T>(value);
        }
        ++m_size;
    }
    std::vector<T> vectorize(){
        std::vector<T> vec;
        vectorRecurse(vec, m_root);
        return vec;
    }

    size_t size() const { return m_size; }

};
#endif