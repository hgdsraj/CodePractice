
#include <string>
#include <iostream> //incase
#include <exception>


struct ALL_REPEAT: public std::exception
{
  virtual const char* what() const throw()
  {
    return "no non repeating characters";
  }
};


char firstNonRepeat(std::string toBeChecked)
{
    int asciiArray[256] = {0};
    int toBeCheckedLength = toBeChecked.length();

    for(int i = 0; i < toBeCheckedLength; i++)
    {
        asciiArray[ (int)toBeChecked[i] - 1 ]++;
    }

    for(int i = 0; i < toBeCheckedLength; i++)
    {
        if(asciiArray[ (int)toBeChecked[i] - 1 ] == 1)
        {
            return toBeChecked[i];
        }
    }
    throw(ALL_REPEAT());

}


int main()
{
    std::string total = "total";
    std::string teeter = "eetterr";

    try
    {
        if(firstNonRepeat(total) == 'o')
            std::cout << "Correct" << std::endl;
    }
    catch(ALL_REPEAT &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        if(firstNonRepeat(teeter) == 'r')
            std::cout << "Correct" << std::endl;
    }
    catch(ALL_REPEAT &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
