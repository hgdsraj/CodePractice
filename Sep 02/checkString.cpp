//There are three types of edits that can be performed on strings, insert a char
// remove a char, or replac ea char/ given two strings, write a function to check
// if they are one edit (or zero edits ) away
//ex
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

#include <string>
#include <iostream>


bool oneEditAway (std::string first, std::string second)
{
    int firstLength = first.length();
    int secondLength = second.length();

    if (abs(firstLength - secondLength) > 1)
    {
      return false;
    }


    std::string longString;
    std::string shortString;
    int longLength;
    int shortLength;

    if (firstLength > secondLength)
    {
        longString = first;
        shortLength = secondLength;
        longLength = firstLength;
        shortString = second;
    }
    else
    {
        longLength = secondLength;
        shortLength = firstLength;
        longString = second;
        shortString = first;
    }

    int shortIndex = 0;
    int longIndex = 0;
    bool foundDifference = false;

    while (shortIndex < shortLength && longIndex < longLength)
    {
        if (shortString[shortIndex] != longString[longIndex])
        {
            if(foundDifference)
            {
                return false;
            }
            foundDifference = true;
            if(shortLength == longLength)
            {
                shortIndex++;
            }
        }
        else
        {
            shortIndex++;
        }
        longIndex++;
    }
    return true;
}

int main()
{
    std::string pale = "pale";
    std::string ple = "ple";
    std::string pales = "pales";
    std::string bale = "bale";
    std::string bake = "bake";
    if (oneEditAway(pale,ple) )
    {
        std::cout << "chedked1" << std::endl;
    }
    if (oneEditAway(pales,pale))
    {
        std::cout << "checked2" << std::endl;
    }
    if (oneEditAway(bale,pale))
    {
        std::cout << "checked3" << std::endl;
    }
    if (oneEditAway(pale,bake))
    {
        std::cout << "shudbefalse" << std::endl;
    }
    else
    {
        std::cout << "checke3" << std::endl;
    }
    return 0;

}
