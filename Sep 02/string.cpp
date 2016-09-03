#include <string>
#include <iostream>
#include <exception>
#include <cstring>
class strException : public std::exception
{
public:
  virtual const char * what() const throw()
  {
    return "ll";
  }
};

bool strStuff(std::string s)
{
  std::cout << (char*)&s << std::endl;
  if(0==1)
  {
    throw(strException());
  }
  for (int i = 0; i < 5; i ++)
  {
    s[i] = 'a';
  }
  return true;
}
int main()
{
  std::string myString = "helloWorld!";
  char * myString2 = "helloWorld!";
  char * myString25 = new char[11];
  for(int i = 0; i < 11; i++)
  {
    myString25[i] = myString2[i];
  }
  std::string myString3(myString2);
  try
  {
    strStuff(myString);
    strStuff(myString2);
    strStuff(myString3);
    strStuff(myString25);
  }
  catch(strException& e)
  {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
