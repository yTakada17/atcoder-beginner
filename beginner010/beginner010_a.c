#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 15

int
main ()
{

  char s[SIZE] = { };
  scanf ("%s", s);

  printf ("%s\n", strcat (s, "pp"));
  return 0;
}
