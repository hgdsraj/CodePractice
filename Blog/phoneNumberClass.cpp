// Create a class that stores unique, unsigned 7-digit integers in sorted order, largest value 9,999,999, smallest 0
//
// Operations include:
//    -Insert a number O(1)
//    -Lookup a number O(1)
//    -Print in sorted order O(10000000)



// Interface

class NumberBase
{
private:
    bool * arrayOfBits;
    const unsigned int CAPACITY = 10000000;

public:
    NumberBase();
    ~NumberBase();

    void insert(int number);
    bool lookup(int number);
    void display();
};

// Implementation

#include <iostream>
#include <NumberBase.h>

NumberBase::NumberBase()
{
    try
    {
        arrayOfBits = new bool[CAPACITY];
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

~NumberBase::NumberBase()
{
    delete[] arrayOfBits;
}

void NumberBase::insert(int number)
{
    if (number >= CAPACITY)
    {
        return;
    }
    arrayOfBits[number] = true;
}

bool NumberBase::lookup(int number)
{
    if (number >= CAPACITY)
    {
        return false;
    }
    if (arrayOfBits[number])
    {
        return true;
    }
    return false;
}

void NumberBase::display()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (arrayOfBits[i])
        {
            std::cout << i << std::endl;
        }
    }
}
