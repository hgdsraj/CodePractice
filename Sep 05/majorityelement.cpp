//a majority element is an element that makes up more than half o the items in a n array
//given an array of integers, find majority element
// if no majority el return -1
// o n time, o 1 space
//example input: {1,2,5,9,5,9,5,5,5}
//example input: {1,1,1,1,1,2,3,4,5}
//example input: {1,2,1,3,1,4,1,5,1}
//example input: {2,1,3,1,1,3,1,1,1}
//array size n, then if i take first half and second half (2 n/2 sized intervals), then i must have atleast n/4 of majoiryt element in each subinterval
//example input: {1,2,3,1,1,3,1,1,1}
//example input: {2,1,1,1,2,1,1,1,2}
//example input: {1,2,3,4,1,1,1,1,1}
//

// return 5
#include <iostream>

bool validate(int * arr, int length, int majority);
int get_candidate(int * arr, int length);
int majority_element(int * arr, int length)
{
     int candidate = get_candidate(arr,length);
     return validate(arr,length,candidate) ? candidate : -1;
}

int get_candidate(int * arr, int length)
{
    int majority = 0;
    int count = 0;
    for(int i = 0; i < (int)length; i++)
    {
        if (count == 0)
        {
            majority = arr[i];
        }
        if (arr[i] == majority)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return majority;
}

bool validate(int * arr, int length, int majority)
{
    int count = 0;

    for (int i = 0; i < (int)length; i++)
    {
        if (arr[i] == majority)
        {
            count++;
        }
    }

    return count > (int)length/2;

}

int main()
{
    int length = 9;

    /*std::cout << majority_element(  {1,2,5,9,5,9,5,5,5}, length ) << std::endl;
    std::cout << majority_element(  {1,1,1,1,1,2,3,4,5}, length )<< std::endl;


    std::cout << majority_element(  {2,1,3,1,1,3,1,1,1}, length )<< std::endl;

    //array size n, then if i take first half and second half (2 n/2 sized intervals), then i must have atleast n/4 of majoiryt element in each subinterval
    std::cout << majority_element(   {1,2,3,1,1,3,1,1,1}, length )<< std::endl;

    std::cout << majority_element(  {2,1,1,1,2,1,1,1,2}, length )<< std::endl;

    std::cout << majority_element(  {1,2,3,4,1,1,1,1,1}, length )<< std::endl;*/

    int arr[length] =  {1,2,1,3,1,4,1,5,1};

    std::cout << majority_element( arr, length )<< std::endl;

    return 0;

}
