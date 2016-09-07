//linked list with merge sort

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility> //swap in C++X | X >= 11

template <class T>
class Node
{
public:
    T data;
    Node * next;
    Node();
    Node(T data_to_be_inserted);
};

template <typename T>
Node<T>::Node()
{
    data = 0;
    next = nullptr;
}

template <typename T>
Node<T>::Node(T data_to_be_inserted)
{
    data = data_to_be_inserted ;
    next = nullptr;
}

//***CLASS LIST**
template <class T>
class List
{
public:
    Node<T> * head;
    Node<T> * tail;
    int size;

    List();
    void merge(Node<T>* first, Node<T>* mid, Node<T>* last);
    Node<T> * get_node(int node_number);

    void merge_sort();
    void merge_sort_helper(int first, int last);

    void insert(T data);
    void populate();

    friend std::ostream& operator<<(std::ostream&os, List * lhs)
    {
        Node<T> * curr = lhs->head;
        os << "[ ";
        while(curr!=nullptr)
        {
            os << curr->data << " ";
            curr = curr->next;
        }
        os << " ]" << std::endl;
        return os;
    }

};
///*** END LIST **//

template <typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <typename T>
Node<T> * List<T>::get_node(int node_number)
{
    Node<T> * current = head;
    for(int i = 0; i < node_number && current->next != nullptr; i++)
    {
        current = current->next;
    }
    return current;
}

template <typename T>
void List<T>::merge(Node<T>* first, Node<T>* mid, Node<T>* last)
{
    List<T> * temp_list = new List<T>;

    Node<T> * first_temp = first;
    Node<T> * mid_temp = mid;
    if(first == nullptr || last ==nullptr || mid == nullptr)
    {
        return;
    }
    while(first_temp != mid && mid_temp != last->next)
    {
        if(first_temp->data <= mid_temp->data)
        {
            temp_list->insert(first_temp->data);
            first_temp = first_temp->next;
        }
        else
        {
            temp_list->insert(mid_temp->data);
            mid_temp = mid_temp->next;
        }
    }


    while(first_temp != mid)
    {
        temp_list->insert(first_temp->data);
        first_temp = first_temp->next;
    }

    while(mid_temp != last->next)
    {
        temp_list->insert(mid_temp->data);
        mid_temp = mid_temp->next;
    }

    Node<T> * temp_list_iterator = temp_list->head;
    while(temp_list_iterator)
    {
        first->data = temp_list_iterator->data;
        first = first->next;
        temp_list_iterator = temp_list_iterator->next;
    }
}

template <typename T>
void List<T>::merge_sort_helper(int first, int last)
{
    if(last<=first)
    {
        return;
    }
    Node<T> * first_node = get_node(first);
    if(first_node == nullptr)
    {
        return;
    }
    int mid = first + (last-first)/2;

    Node<T> * mid_node = get_node(mid+1);
    Node<T> * last_node = get_node(last);
    if(mid_node == nullptr || last_node == nullptr)
    {
        return;
    }
    std::cout << first_node->data << " " << mid_node->data << " " << last_node->data << std::endl;
    merge_sort_helper(first,mid);
    merge_sort_helper(mid+1,last);
    merge(first_node,mid_node,last_node);
}

template <typename T>
void List<T>::merge_sort()
{
    if(head==nullptr || head->next->next == nullptr)
    {
        return;
    }
    merge_sort_helper(0,size-1);
}

template <typename T>
void List<T>::populate()
{
    const int MAX_RAND = 100;
    for(int i = 0; i < MAX_RAND; i++)
    {
        insert(rand() % MAX_RAND);
    }
}

template <typename T>
void List<T>::insert(T data)
{
    if(!head)
    {
        try
        {
            head = new Node<T>;
            head->data = data;
            tail = head;
        }
        catch(std::exception& e)
        {
            std::cout << "ERROR! " << std::endl;
            std::cout << e.what() << std::endl;
        }
        size++;
        return;
    }
    if(head==tail)
    {
        try
        {
            head->next = new Node<T>;
            head->next->data = data;
            tail = head->next;
        }
        catch(std::exception& e)
        {
            std::cout << "ERROR! " << std::endl;
            std::cout << e.what() << std::endl;
        }
        size++;
        return;
    }

    try
    {
        tail->next = new Node<T>;
        tail->next->data = data;
        tail = tail->next;
    }
    catch(std::exception& e)
    {
        std::cout << "ERROR! " << std::endl;
        std::cout << e.what() << std::endl;
    }
    size++;
    return;

}

int main()
{
    List<int> * my_list;
    try
    {
        my_list = new List<int>;
    }
    catch(std::exception& e)
    {
        std::cout << "ERROR! " << std::endl;
        std::cout << e.what() << std::endl;
    }

    my_list->populate();
    std::cout << my_list << std::endl;

    std::cout << "SORTING! " << std::endl;
    my_list->merge_sort();
    std::cout << "SORTED!" << std::endl;
    std::cout << my_list << std::endl;
    return 0;


}
