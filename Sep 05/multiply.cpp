//job is to write methods to implement multiply, subract, and divide for integers
//using only add operator " + " 1 + 1 = 2; add()?
#include <cmath> //-std=gnu++11 or c++11
#include <iostream>


int add(int x, int y)
{
    int carry = 0;
    while(y!=0)
    {
        carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }

    return x;
}

int multiplication_helper(int smaller, int larger)
{
    int result = 0;

    for(int i = 0; i < smaller; i++)
    {
        result += larger;
    }

    return result;
}

int multiplication_helper_negative(int smaller, int larger)
{
    int result = 0;

    for(int i = 0; i < smaller; i++)
    {
        result -= larger;
    }
    return result;
}


int multiplication(int x, int y)
{
    bool negative = false;

    if(x < 0 && y < 0) //x AND y BOTH < 0
    {
       negative = false;
       x = abs(x);
       y = abs(y);
    }
    else if(y < 0 || x < 0) // x < 0 XOR y < 0
    {
        x = abs(x);
        y = abs(y);
        negative = true;
    }

    if(x < y)
    {
        return  (negative ?  multiplication_helper_negative(x,y) :  multiplication_helper(x,y));
    }

    return (negative ? multiplication_helper_negative(y,x) : multiplication_helper(y,x));

}



int main()
{
    std::cout << "2*2 is " << multiplication(2,2) << std::endl;
    std::cout << "-2*2 is " << multiplication(2,-2) << std::endl;
    std::cout << "-2*-2 is " << multiplication(-2,-2) << std::endl;
    return 0;
}
