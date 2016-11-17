// 0 = 3
// 1 = 3 ... etc
#include <string>
#include <iostream>
#include <utility>
#include <fstream>
using namespace std;

int tohex(char conv)
{
  int x = conv;
  if(x > 64 && x < 76)
    x = x - 55;
  if(x < 58 && x > 47)
    x = x - 48;
  return x;
}
int run(string to_be_converted)
{

  int k = -1;
  string result = "";
  int length = to_be_converted.length();
  for(int i = 0; i < length; i++)
  {
    string to_append;

    if(to_be_converted[i] == (char)'\\')
    {
      i++;
      char conv = to_be_converted[i];
      if(isalnum(conv))
      {
        if((conv >= '0' && conv <= '9') || (conv >= 'A' && conv < 'G'))
        {
          if(i + 1 < length)
          {
            to_append = to_be_converted.substr(i+1,1);
            char to_appends = to_append[0];
            if((to_appends >= '0' && to_appends <= '9') || (to_appends >= 'A' && to_appends < 'G'))
            {
              int lim = tohex(conv);
              for(int j = 0; j < lim+3; j++)
              {
                result.append(to_append);
              }
            }
            else
            {
              cout << "CORRUPTED" << endl;
              return 0;
            }

          }
          else
          {
            cout << "CORRUPTED" << endl;
            return 0;
          }
        }
        else
        {
          cout << "CORRUPTED" << endl;
          return 0;
        }
      }
      else
      {
        cout << "CORRUPTED" << endl;
        return 0;
      }
    }
    else
    {
      char to_appendz = to_be_converted[i];
      if((to_appendz >= '0' && to_appendz <= '9') || (to_appendz >= 'A' && to_appendz < 'G') || to_appendz == '\n' || to_appendz == '#' || to_appendz == '\r')
      {
        result.append(to_append);
      }
      else
      {
        cout << "CORRUPTED" << endl;
        return 0;
      }
    }
  }

  cout << result << endl;
  return 0;

}

int main()
{
  fstream input_file;
  input_file.open("Q1in");
  if (!input_file)
  {
    cout << "err" << endl;
    return 0;
  }


  while(!input_file.eof()) {
    string filestring = "";
    getline(input_file, filestring);
    run(filestring);

  }
return 0;


}
