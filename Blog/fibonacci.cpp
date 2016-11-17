
#include <iostream>

int get_nth_fibonacci(int previous, int current, int depth, const int MAX_DEPTH)
{
    int temp = current;
    current = current+previous;
    previous = temp;
    depth++;
    if(depth==MAX_DEPTH)
        return current;
    return get_nth_fibonacci(previous,current,depth,MAX_DEPTH);
}

int get_nth_fibonacci(const int MAX_DEPTH)
{
    if(MAX_DEPTH == 0)
    {
        return 0;
    }
    if(MAX_DEPTH == 1)
    {
        return 1;
    }
    if(MAX_DEPTH == 2)
    {
        return 1;
    }

    return get_nth_fibonacci(1,1,2,MAX_DEPTH);
}

void fibonacci(int previous, int current, int depth, const int MAX_DEPTH)
{
    int temp = current;
    current = current+previous;
    previous = temp;
    depth++;
    std::cout << current << " " << std::endl;
    if(depth==MAX_DEPTH)
    {
        return;
    }
    return(fibonacci(previous,current,depth,MAX_DEPTH));
}
void fibonacci(const int MAX_DEPTH)
{
    std::cout << 1 << " " << std::endl;
    std::cout << 1 << " " << std::endl;

    return fibonacci(1,1,2,MAX_DEPTH);
}

int main()
{
    fibonacci(10);
    return 0;
}
