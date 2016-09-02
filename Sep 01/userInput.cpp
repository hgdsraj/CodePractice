#include <limits>
#include <iostream>

/*
int userInt()
{
    int userInput = -1;
    std::cout << "Please input a valid integer." << std::endl;
    while (!(std::cin >> userInput))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please input a valid integer." << std::endl;
    }
    return userInput;
}

*/
int userInt()
{
    int userInput;
    std::cin >> userInput;
    while (std::cin.fail())
    {
        std::cout << "Please enter a valid integer value!" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> userInput;
    }
    return userInput;
}

int main()
{
    int input = userInt();

    std::cout << "success, you input : " << input << std::endl;
    return 0;
}
