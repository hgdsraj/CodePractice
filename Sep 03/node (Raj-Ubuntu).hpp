//node should have insert delete, set data, print

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
    std::cout << data << std::endl;
    if (left!=nullptr)
    {
        left->print_in_order();
    }

    if (right!=nullptr)
    {
        right->print_in_order();
    }
}

template <typename T>
void node<T>::insert(T data_to_insert)
{
    if (data<=data_to_insert)
    {
        if (right==nullptr)
        {
            right = new node<T>(data_to_insert);
        }
        else
        {
            left->insert(data_to_insert);
        }
    }
    else
    {
        if (left==nullptr)
        {
            left = new node<T>(data_to_insert);
        }
        else
        {
            left->insert(data_to_insert);
        }
    }
    }
}
