#include <string>
#include <iostream>
using namespace std;

void get( string str, string res ) {

   cout << res << endl;

   for( int i = 0; i < str.length(); i++ )
      get( string(str).erase(i,1), res + str[i] );
}

int main( int argc, char **argv) {

   string str = "123";
   get( str, "" );
   return 0;
}
