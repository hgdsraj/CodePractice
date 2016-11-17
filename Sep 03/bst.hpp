//make a bst
//bst should have node * root
//
#include <iostream>
#include "node.hpp"

#ifndef __BST_HPP__
#define __BST_HPP__

template <class T>
class bst
{
private:
    node<T> * root;
public:
    bst();
    bst(node<T> root);
    ~bst();

    void print_in_order();
    void print_post_order();

    void bfs();
    void dfs();

    node<T>* search(T key);
    node<T>* search(node<T>& key);

    void insert(T data);
    void insert(node<T> data);

};
#endif

template <typename T>
bst<T>::bst()
{
    root = nullptr;
}

template <typename T>
void bst<T>::print_in_order()
{
    root->print_in_order();
}

template <typename T>
void bst<T>::insert(T data)
{
    if(root==nullptr)
    {
        root->set_data(data);
    }
    else
    {
        root->insert(data);
    }
}

template <typename T>
void bst<T>::insert(node<T> data)
{
    if(root==nullptr)
    {
        root = data;
    }
    root->insert(data);
}
