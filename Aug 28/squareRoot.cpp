//Implement a funciton that computes/approximates the square root of a number
// x = integer without using sqrt from cmath
//can use other shit from cmath doe
// pow (4.73, 12.0)

#include <iostream>
#include <cmath>
#include <utility>


bool errorCheckSquareRoot(int x, int result)
{
    if(abs(result^2 - x) <= 0.001)
    {
        return true;
    }
    return false;
}

float squareRoot(int x)
{
    int i;
    for(i = 0; i*i < x; i++)

    float j= static_cast<float>(i) - 1;

    while( !errorCheckSquareRoot(x, j))
        j += 0.0001;

    return j;

}

int main()
{
    int x = 5;
    int y = 144;

    if(errorCheckSquareRoot(x,squareRoot(x))
    {
        std::cout << "Test 1 passed" << std::endl;
    }

    if(errorCheckSquareRoot(y,squareRoot(y))
    {
        std::cout << "Test 2 passed" << std::endl;
    }

    return 0;
}
