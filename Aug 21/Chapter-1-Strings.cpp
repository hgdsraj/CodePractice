/*
*   This program is for chapter one of cracking the coding interview
*
*
*
*
*
*
*/

#include <iostream>

using namespace std;


//Generates an int array which is a palindrome from a given array
//Chops in half, takes first half and copies backwards to second
//PRE: arr is allocated correctly, and valid pointer to an array of length len
//POST: arr is a palindrome of length len, consisting of first half,
//          followed by first half backwards
void genPalindromeArray(int * arr, int len)
{
    if(arr == nullptr || len < 2) //error checks
    {
        return;
    }

    for(int i = 0; i < len/2; i++) // len/2 accounts for both odd and even cases
    {
        arr[len-1-i] = arr[i];
    }
}

//PRE: arr is an integer array of length len
//POST: returns true if arr was a palindrome
//          ie: arr[i] == arr[len-1-i] for all i < len/2
bool isPalindrome(int * arr, int len)
{
    if(arr == nullptr || len < 1)
    {
        return false;
    }

    for(int i = 0; i < len/2; i++)
    {
        if(arr[i] != arr[len-i-1])
        {
            return false;
        }
    }
    return true;
}

void genAscendingArray(int * arr, int len)
{
    if(arr == nullptr || len < 1) //error checks
    {
        return;
    }

    for(int i = 0; i < len; i++) // len/2 accounts for both odd and even cases
    {
        arr[i] = i;
    }
}

void genAscendingArray(char * arr, int len)
{
    if(arr == nullptr || len < 1) //error checks
    {
        return;
    }

    for(int i = 0; i < len; i++) // len/2 accounts for both odd and even cases
    {
        arr[i] = (char)i;
    }
}

//PRE: string has only ASCII chars (256 possible)
//POST: returns true if arr had all unique values, false otherwise
//assumes chars
bool isUnique(char* arr, int len)
{
    if(arr == nullptr || len < 1)
    {
        return false;
    }

    bool * charTable = new(nothrow) bool[256](); //ASCII means 256 chars! false

    if(charTable == nullptr)
    {
        return false;
    }

    for(int i = 0; i < len; i++)
    {
        bool currCharTablePosVal = charTable[ (int)arr[i] ];
        if(currCharTablePosVal) //if true, then we know this val already existed
        {
            return false;
        }
        else
        {
            charTable[ (int)arr[i] ] = true;
        }
    }

    return true;
}

//Generates a pseudo-random array using cstdlib built in random function where
//          the lower bound is 0 and the upper bound is given by lim
//PRE: arr is allocated correctly, and valid pointer to
//          writeable memory of size sizeof(int)*len (varies by system)
//POST: arr is now filled with pseudo-random integers in range [0,lim] unless
//          lim < 1, in which case arr set to DEFAULT_MAX_LIM (set to 10 init)
void genRandomArray(int * arr, int len, int lim)
{
    const int DEFAULT_MAX_LIM = 10;

    if(arr == nullptr || len < 1) //error checks
    {
        return;
    }

    if(lim < 1) //make sure limit is correct
    {
        lim = DEFAULT_MAX_LIM;
    }

    for(int i = 0; i < len; i++) // len/2 accounts for both odd and even cases
    {
        arr[i] = rand() % lim;
    }

    return;
}


//Generates a pseudo-random array using cstdlib built in random function (ASCII)
//PRE: arr is allocated correctly, and valid pointer to
//          writeable memory of size sizeof(char)*len (varies by system)
//POST: arr is now filled with pseudo-random characters
void genRandomArray(char * arr, int len)
{

    if(arr == nullptr || len < 1) //error checks
    {
        return;
    }

    for(int i = 0; i < len; i++) // len/2 accounts for both odd and even cases
    {
        arr[i] = (char)(rand() % 256);
    }
    return;
}

//Prints array arr of length len to cout (std:ostream)
//PRE: arr is allocated correctly, and valid pointer to an array of length len
//POST: arr is printed to std:ostream in format "[ i, j k, l ]\n"
void printArray(int * arr, int len)
{
    cout << "[ ";

    if(arr == nullptr || len < 1) //error checks
    {
        cout << " ]" << endl;
        return;
    }

    for(int i = 0; i < len/2; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << " ]" << endl;
    return;
}

int main()
{
    const int MAX_LEN = 20; //arrays length
    int len = MAX_LEN; //array length set to max len by DEFAULT_MAX_LIM

    int * intArr = new(nothrow) int[len]; //nothrow to comply with error checks
    char * charArr = new(nothrow) char[len]; //nothrow to comply with error checks
    char * charrArrDup = charArr; //simple duplicate to check permutation

    //genRandomArray(arr,len,len); //generate a random array
    //test
    //printArray(arr,len);
    genAscendingArray(intArr,len); //generate a ascending array: arr[i] < arr[i+1]
    genAscendingArray(charArr,len); //generate random char array

    if(isUnique(charArr,len)) //see if our array has any duplicates!
    {
        cout << "The array has all unique values!" << endl;
    }
    else
    {
        cout << "The array is not fully unique." << endl;
    }

    genPalindromeArray(intArr,len); //convert to palindrome
    //printArray(arr,len);

    if(isPalindrome(intArr,len)) //find out if is palindrome
    {
        cout << "The Array is a palindrome!" << endl;
    }
    else
    {
        cout << "The Array is not a palindrome!" << endl;
    }

    return 0;
}
