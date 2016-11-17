#include <iostream>
#include <string>
using namespace std;

int search()
int main()
{
    int len = 10;
    string input[len];
    string result[len];
    int i = 0;
    input[i++] = "-LLLWLLLLW";
    input[i++] = "W-LWLWLWWW";
    input[i++] = "WW-WWWLWWL";
    input[i++] = "WLL-WWWWLW";
    input[i++] = "LWLL-WLWWW";
    input[i++] = "WLLLL-WLWW";
    input[i++] = "WWWLWL-WLL";
    input[i++] = "WLLLLWL-LL";
    input[i++] = "WLLWLLWW-L";
    input[i++] = "LLWLLLWWW-";

    int k = len-1;

    for(int i = 0; i < len; i++)
    {
      if(input[i][k] == 'W')
      {

      }
    }

    return 0;
}
