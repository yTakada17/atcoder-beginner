#include<stdio.h>

int
main ()
{
  char c;
  scanf ("%c", &c);

  printf ("%d\n", c - 'A' + 1);
  return 0;
}
