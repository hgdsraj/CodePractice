// Given a string, return a new string that
// is a reversed version of the original string

#include <string>
#include <iostream>


using namespace std;

string reverse(string origStr)
{
    int len = origStr.length();

    if (len == 0)
    {
        return origStr;
    }

    string reversed(len, ' ');

    for (int i = len - 1; i >= 0; i--)
    {
        reversed[len - 1 - i] = origStr[i];
    }

    return reversed;
}



int main()
{
    string toBeReversed = "Hello, World!";

    cout << reverse(toBeReversed) << endl;

    return 0;

}
