//tasc
// write a function to determine if two strings are anagrams of eachother
// if one string is a shufled version of another
// input: two strings
// uppercase/lowercase dont matter


#include <string>
#include <cctype>
#include <iostream>

bool isAnagram(std::string firstString, std::string secondString)
{
    int firstStringLength = 0;
    int secondStringLength = 0;

    int firstStringSum = 0;
    int secondStringSum = 0;

    while(firstString[firstStringLength] != '\0')
    {
        firstStringSum += (int)std::tolower(firstString[firstStringLength]);
        firstStringLength++;
    }

    while(secondString[secondStringLength] != '\0')
    {
        secondStringSum += (int)std::tolower(secondString[secondStringLength]);
        secondStringLength++;

    }

    if(firstStringLength == secondStringLength && firstStringSum == secondStringSum)
    {
        return true;
    }
    return false;

}

int main()
{
    std::string str1 = "helslo";
    std::string str2 = "elloH";

    if(isAnagram(str1,str2))
    {
        std::cout << "ITWORKED" << std::endl;
    }

}
