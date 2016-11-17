// Find the maximum continuous subsequence of an array and print where it begins, where it ends, and its sum.



//out: pos 0 = begin, 1 = end, 2 = sum
//len is length of array
//out has length 3

#include <iostream>

void maxContSubarray(int * array, int len, int * out)
{
    int trueMax = 0;
    int maxEndingHere = 0;
    int begin;
    int tempBegin;
    int end;

    for (int i = 0; i < len; i++)
    {
        maxEndingHere = maxEndingHere + array[i];

        if (maxEndingHere < 0)
        {
            maxEndingHere = 0;
            tempBegin = i+1;
        }

        if (trueMax < maxEndingHere)
        {
            trueMax = maxEndingHere;
            begin = tempBegin;
            end = i;
        }
    }

    if(begin < end)
    {
        out[0] = begin;
        out[1] = end;
        out[2] = trueMax;
    }
    return;

}




int main()
{

    int len = 12;
    int array[len] = {-1,-1000,-2,3,4,5,3,1,3,-1000,3,5};

    int * out = new int[3];

    maxContSubarray(array,len,out); //should put in out 3 as start, 8 as end, and 19 as sum

    std::cout << "The sum of the sequence is: " << out[2] << std::endl;
    std::cout << "The beginning of the sequence is: " << out[0] << std::endl;
    std::cout << "The end of the sequence is: " << out[1] << std::endl;

    return 0;
}
