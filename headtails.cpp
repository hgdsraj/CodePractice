#include <iostream>
#include <string>
#include <cstdlib> //rand, srand
#include <ctime> // time

std::string getcoin()
{
    std::srand(std::time(0));
    if(rand() % 2 + 1 == 1)
    {
        return "Heads";
    }
    return "Tails";
}

int main()
{
    std::cout << getcoin() << std::endl;
    return 0;
}
