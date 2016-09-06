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

    void merge_sort();
    void merge_sort_helper(Node<T>* first, Node<T>* mid, Node<T>* last);

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
void List<T>::merge(Node<T>* first, Node<T>* mid, Node<T>* last)
{

}

template <typename T>
void List<T>::merge_sort_helper(int first, int mid, int last)
{
    int mid = size/2;
}

template <typename T>
void List<T>::merge_sort()
{
    if(head==nullptr || head->next->next == nullptr)
    {
        return;
    }
    merge_sort_helper(head)
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
    return 0;


}
