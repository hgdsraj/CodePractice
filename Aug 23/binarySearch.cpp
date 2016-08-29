//func uses bin srch 2 determine whthr el <int> in arr <int>
//n datas <int>
//given length
//arr int *, len <int>, int target
//return true or false if in or not in
//return false if probs
//arr sorted [i] < [i+1] all i >=0 < len
//[1, 2, 3, 4, 5]

#include <iostream>



//helper for binary Search
bool binarySearchHelper(int * arr, int first, int last, int target)
{
    if(last-first <= 0)
    {
        return false;
    }

    int mid = first + (last-first)/2;

    if(target == arr[mid]) //checked mid
    {
        return true;
    }


    if(target < arr[mid])
    {
        return binarySearchHelper(arr, first, mid, target);
    }
    else
    {
        return binarySearchHelper(arr, mid, last, target);
    }

}


//returns true if target exists in arr, false otherwise
bool binarySearch(int * arr, int len, int target)
{
    return len <= 0 ? false : binarySearchHelper(arr, 0, len-1, target);
}


int main()
{
    int len = 8;
    int * arr = new int[len];

    for(int i = 0; i < len; i++)
    {
        arr[i] = i;
    }

    if(binarySearch(arr, len, 4))
    {
        std::cout << "Four found" << std::endl;
    }
}

struct binaryNode {
    int data;
    binaryNode * left;
    binaryNode * right;
};

struct binaryTree {
  binaryNode * root;
};
