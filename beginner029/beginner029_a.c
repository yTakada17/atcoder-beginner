#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 11
int
main ()
{

  char str[SIZE] = { };

  scanf ("%s", str);
  printf ("%s\n", strcat (str, "s"));

  return 0;
}
