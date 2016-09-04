//node should hae

#ifndef __NODE_HPP__
#define __NODE_HPP__

template <class T>
class node
{
private:
    T data;
    node* left;
    node* right;

public:
    node();
    node(T data);
    node(node<T> left = nullptr, node<T> right = nullptr);

    void print_in_order();
    void insert(T data);
    void insert(node<T> data);
    void set_data(T data);
};

#endif

template <typename T>
node<T>::node()
{
    left = nullptr;
    right = nullptr;
    data = 0;
}

template <typename T>
node<T>::node(T data_set)
{
    left = nullptr;
    right = nullptr;
    data = data_set;
}

template <typename T>
void node<T>::print_in_order()
{

}

void node<T>::insert(T data)
{
    if (data<=)
}
