#include<stdio.h>

int
main ()
{
  char s[100] = { };
  int i = 0;

  scanf ("%s", s);
  scanf ("%d", &i);
  printf ("%c\n", s[i - 1]);
  return 0;
}
