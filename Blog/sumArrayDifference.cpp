//sum swap
// given two array of integers, find a pair of values that you can swap to give the two arrays the same sum
//[4.1.2.1.1.2] & [3.6.3.3]
// sum1 = 11
// sum2 = 15
// diff = 4
// I need two values, one from array1, one from array2 S.T their sum = 4
//return null if no solution
//return : [1.3]
//cannot be negative values

int sum(int array, int len)
{
    int sumOfArray = 0;
    for(int i = 0; i < len; i++)
    {
        sumOfArray += array[i];
    }
    return sumOfArray;
}


//finds a value in arrOne and arrTwo such that swapping them
//    gives each array the same sum.
//POST: returns two integers that are to be swapped in an array of length 2.
//worst case running time lenOne*lenTwo
//nlogn ->mergesort
//n = length of larger array
//n
int * sumSwap(int * arrOne, int & arrTwo, int lenOne, int lenTwo)
{
    if(arrOne && arrTwo)
    {
        int sumOfArrayOne = sum(arrOne,lenOne);
        int sumOfArrayTwo = sum(arrTwo,lenTwo);
        int difference = abs(sumOfArrayOne - sumOfArrayTwo);
    }

    for(int i = 0; i < lenOne; i++)
    {
        if(arrOne[i] <= difference)
        {
            for(int j = 0; j < lenTwo; j++)
            {
                if(arrTwo[j] + arrOne[i] == difference)
                {
                    int * toBeReturned = new int[2];
                    toBeReturned[0] = arrOne[i];
                    toBeReturned[1] = arrTwo[j];
                    return toBeReturned;
                }
            }
        }
    }


    return nullptr;
}
