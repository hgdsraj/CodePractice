//in c++, implement a bubble sort
//ascending order
//some array of
//compares pairs of values

#include <iostream>
#include <cstdlib>
#include <utility>

typedef int dankMeme;

//assumes array is of length len, and allocated correctly
void bubbleSort (dankMeme* array, dankMeme len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < (len - i - 1); j++)
        {
            if (array[j+1] < array[j])
            {
                std::swap(array[j+1],array[j]);
            }
        }
    }

    return;
}

//assumes array is of length len, and allocated correctly
void makeArray (dankMeme * array, dankMeme len)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = rand() % len+len;
    }
    return;
}

//assumes array is of length len, and allocated correctly
bool checkSorted (dankMeme * array, dankMeme len)
{
    for (dankMeme i = 0; i < len-1; i++)
    {
        if (array[i] > array[i+1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    dankMeme len = 100;
    dankMeme * array = new dankMeme[len];
    makeArray(array,len);
    bubbleSort(array,len);
    if ( checkSorted(array,len) )
    {
        std::cout << "array sorted!" << std::endl;
    }
    else
    {
        std::cout << "array not sorted!" << std::endl;
    }

    return 0;
}
