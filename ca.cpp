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
    if (toBeTested == "")
    {
        return true;
    }

    string toBeTestedNew = "";
    for (int i = 0; i < toBeTested.length(); i++)
    {
        if (isalnum(toBeTested[i]))
        {
            toBeTestedNew += toBeTested[i];
        }
    }

    for (int i = 0; i < toBeTestedNew.length(); i++)
    {
        toBeTestedNew[i] = tolower(toBeTestedNew[i]);
    }

    string reversed = "";

    for (int i = toBeTestedNew.length() - 1; i > -1; i--)
    {
        reversed += toBeTestedNew[i];
    }

    if (toBeTestedNew.compare(reversed) == 0)
    {
        return true;
    }
    return false;
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
