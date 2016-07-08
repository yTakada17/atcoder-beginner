#include <stdio.h>

int
main ()
{
  int a;
  char s[6];
  scanf ("%s %d", s, &a);
  a--;
  printf ("%c%c\n", s[a / 5], s[a % 5]);
  return 0;
}
