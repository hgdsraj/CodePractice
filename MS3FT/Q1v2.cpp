// 0 = 3
// 1 = 3 ... etc
#include <string>
#include <iostream>
#include <utility>
#include <fstream>
#include <regex>
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
bool allowable(string test)
{
	regex allowed("[A-F0-9]*\\\\[A-F0-9]{2,}");
  smatch match;
  int length = test.length();
  string to_test = test;
  string to_confirm = "";
  int i = length;
  int pos = 0;
  while(i > 0)
  {
    if(regex_search(to_test, match, allowed)){
        to_confirm.append(match[0]);
    }
    pos += match[0].length();
    if(pos < length)
    {
      to_test = test.substr(pos);
    }
    else
    {
      break;
    }
    i = match[0].length();
  }
  if(to_confirm == test)
  {
    return true;
  }
  return false;
}

int run(string to_be_converted)
{
  if(!allowable(to_be_converted))
  {
    cout << "CORRUPTED" << endl;
    return 0;
  }
  int k = -1;
  string result = "";
  int length = to_be_converted.length();
  for(int i = 0; i < length; i++)
  {
    string to_append = to_be_converted.substr(i,1);

      if(to_be_converted[i] == (char)'\\')
      {
        i++;
        char conv = to_be_converted[i];
        int conv_to_int = tohex(conv);
        to_append = to_be_converted.substr(i+1,1);
        for(int j = 0; j < conv_to_int + 2; j++)
        {
          result.append(to_append);
        }
      }
      else{
        result.append(to_append);
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
    run(filestring.substr(0,filestring.length()-1));

  }
  run("0\\083ACD4\\5B007AA2F");
  run("\\2C");
return 0;


}
