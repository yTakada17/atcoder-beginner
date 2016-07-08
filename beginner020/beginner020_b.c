#include<stdio.h>
int
main ()
{
  int a, b;
  int c;
  scanf ("%d %d", &a, &b);
  if (b < 10)
    {
      c = 10;
    }
  else if (b < 100)
    {
      c = 100;
    }
  else
    {
      c = 1000;
    }
  printf ("%d\n", (a * c + b) * 2);
  return 0;
}
