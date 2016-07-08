#include<stdio.h>

int
main ()
{
  int a, b, c;
  scanf ("%d %d %d", &a, &b, &c);
  printf ("%d\n", a * b * c % (1000000000 + 7));

  return 0;
}
