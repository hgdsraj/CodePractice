#include <iostream>
#include <vector>

template <typename T>
int find_max_k(std::vector<T>);

template <typename T>
int get_subsequences_count(int k, std::vector<T> ropes);

template <typename T>
int get_subsequences_count(int k, std::vector<T> ropes)
{
    int count = 0;
    int current_size = 0;

    for(int i = 0; i < ropes.size(); i++)
    {
        current_size += ropes[i];

        if(current_size >= k)
        {
            current_size = 0;
            count++;
        }
    }
    return count;
}

template <typename T>
int find_max_k(std::vector<T> ropes)
{
    for(int i = 0; i < ropes.size(); i++)
    {
        int total = get_subsequences_count(i, ropes);
        if(total == i)
        {
            return total;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> ropes = {1,9,5,3,2,5,1,2};
    std::cout << "MAX k where amount of ropes are length k and size k is " << find_max_k(ropes) << std::endl;
    return 0;
}
