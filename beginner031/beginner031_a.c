#include<stdio.h>

int
main ()
{
  int a = 0, d = 0;

  scanf ("%d %d", &a, &d);
  if ((a + 1) * d > a * (d + 1))
    {
      printf ("%d\n", (a + 1) * d);
    }
  else
    {
      printf ("%d\n", a * (d + 1));
    }

  return 0;
}
