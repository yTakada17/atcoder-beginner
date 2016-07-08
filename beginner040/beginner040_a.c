#include<stdio.h>

int
main ()
{
  int n, x;
  scanf ("%d %d", &n, &x);
  int next = 0;
  printf ("%d\n", (x <= (n / 2)) ? x - 1 : n - x);

  return 0;
}
