#include <stdio.h>
int
main ()
{
  int a, b, c, d, e;
  scanf ("%d", &a);
  scanf ("%d", &b);
  scanf ("%d", &c);
  scanf ("%d", &d);
  scanf ("%d", &e);
  if (b - a > d - c)
    printf ("%d\n", b + c + e);
  else
    printf ("%d\n", a + d + e);
  return 0;
}
