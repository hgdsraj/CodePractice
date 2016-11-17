//main driver for bst and node

//#include <bst.h>
#include <iostream>
#include "bst.hpp"

void populate(bst<int> * binary_search_tree)
{
    for (int i = 0; i < 1000; i++)
    {
        binary_search_tree->insert(i);
    }
}

int main()
{
    bst<int>* binary_search_tree  = new bst<int>;
    populate(binary_search_tree);

    binary_search_tree->print_in_order();
    return 0;
}
