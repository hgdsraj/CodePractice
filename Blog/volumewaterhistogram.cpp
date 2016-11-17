// Imagine a histogram
// Design an algorithm to compute the volume of water it could hold if someone poured water across the top
// You can assume that each bar's width is 1
// example, input {0,0,4,0,0,6,0,0,3,0,5,0,1,0,0,0}, output 26
//leftMax = {0,0,4,4,4,6,6,6,3,3,5,5,1,1,1,1}
//rightMax = {4,4,4,6,6,6,3,3,3,5,5,1,1,0,0,0}
//miniMax = {0,0,4,4,4,6,3,3,3,3,5,1,1,0,0,0}
#include <algorithm>
#include <cstdio>

void print_array(int * arr, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int histogramVolume(int * arr, int length)
{

    int leftMax[length] = {0};
    int rightMax[length] = {0};
    int miniMax[length] = {0}; //minimax is the minimum of two maxes
    int currLeftMax = 0, currRightMax = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] > currLeftMax)
        {
            currLeftMax = arr[i];
        }
        leftMax[i] = currLeftMax;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        if (arr[i] > currRightMax)
        {
            currRightMax = arr[i];
        }
        rightMax[i] = currRightMax;
    }

    for (int i = 0; i < length; i++)
    {
        miniMax[i] = std::min(leftMax[i], rightMax[i]);
    }

    //print_array(leftMax,length);
    //print_array(rightMax,length);
    //print_array(miniMax, length);
    //print_array(arr,length);




    int volume = 0;
    for(int i = 0; i < length; i++)
    {
        volume += (miniMax[i] - arr[i]);
    }
    return volume;


}

int main()
{
    int length = 16;
    int arr[length] = {0,0,4,0,0,6,0,0,3,0,5,0,1,0,0,0};
    if(histogramVolume(arr, length) == 26)
        printf("it worked!\n");
    else
        printf("nope it ez %d\n", histogramVolume(arr,length));

    return 0;
}
