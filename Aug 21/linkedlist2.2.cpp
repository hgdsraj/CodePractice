//Finds the kth to last element in a SHSLList
#include <iostream>

Using namespace std;


template <class T>
class node
{
public:
    node * next;
    T * data;
}

template <class T>
class SHSLList
{
Private:

    Int findlen()
    {
        Node * curr = head;
        Int i = 0;

        while(curr != nullptr)
        {
            Curr = curr->next
            i++;
        }
        Return i;
    }

public:
    node<T> * head;
    SHSLList;
    ~SHSLList;

    //insert at head
    bool insert(node<T> * node);

    //finds kth to last element
    node<T> * findNode(int k)
    {
        Int len = findlen();
        if(len == 0) //if length is zero
        {
          Return nullptr;
        }

       Int j = len - k; //j is the jth position (len - k)
    if(j > len)
    {
        Return nullptr;
    }

    Int currCount = 0;
    node<T> * Curr = head;
    while(curr != nullptr)
    {
        currCount++;
        if(currCount == j)
        {
            Return curr;
        }
    }
    Return nullptr;
}


}

//Finds the kth to last element in a SHSLList
Int main()
{
    int k = 12; //element to find

    SHSLList<int> * list;

    node<int> * j = list.findNode(k); //j = kth to last element in our list list

    Cout << “kth to last element is “ << j.data << endl;

    Return 0;
}
