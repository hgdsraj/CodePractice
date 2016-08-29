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
#include <string>
#include <cctype>

using namespace std;

//isalnum(char)


//POST: returns true if toBeTested was a palindrome
bool isPalindrome(string toBeTested)
{
    int i = 0;
    int len = toBeTested.length();
    int k = len-1;

    while(i < j)
    {
        while(!isalnum(toBeTested[i]) && i < j)
        {
            i++;
        }
        while(!isalnum(toBeTested[k]) && i < j)
        {
            k--;
        }

        if(tolower(toBeTested[i]) == tolower(toBeTested[k]))
        {
            i++;
            k--;
        }
        else
        {
            return false;
        }
    }
    return true;
}


int main()
{

    string palindrome = "A man, A plan, a canal, panama"; //true
    string palindrome2 = "lipshitzztihspil"; //true
    string notPalindrome = "seepluzpluz"; //not palindrome


    if(isPalindrome(palindrome)) //find out if is palindrome
    {
        cout << "The Array is a palindrome!" << endl;
    }
    else
    {
        cout << "The Array is not a palindrome!" << endl;
    }

    if(isPalindrome(palindrome2)) //find out if is palindrome
    {
        cout << "The Array is a palindrome!" << endl;
    }
    else
    {
        cout << "The Array is not a palindrome!" << endl;
    }

    if(isPalindrome(notPalindrome)) //find out if is palindrome
    {
        cout << "The Array is a palindrome!" << endl;
    }
    else
    {
        cout << "The Array is not a palindrome!" << endl;
    }

    return 0;
}
