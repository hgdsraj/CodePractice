/*
   Write a C program to find out if the underlying
   architecture is little endian or big endian.
 */
 //higher memory (big endian)
//     ----->
//+----+----+----+----+
//|0x76|0x54|0x32|0x10|
//+----+----+----+----+
//A

//higher memory (little endian)
//+----+----+----+----+
//|0x10|0x32|0x54|0x76|
//+----+----+----+----+

#include <stdio.h>
int main ()
{
  unsigned int x = 0x 76 54 32 10;  //4 bytes, 0x signifies its hex
  printf("sizeof(x) is %d\n",(int) sizeof(x)); // 4
  char *c = (char*) &x;
  printf("sizeof(*c) is %d\n", (int)sizeof(*c)); // 1
  printf("sizeof(char) is %d\n", (int)sizeof(char)); // 1


  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }

  return 0;
}
