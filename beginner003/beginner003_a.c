#include<stdio.h>

int
main ()
{

  int n = 0;
  int i = 0;
  int sum = 0;

  scanf ("%d", &n);
  for (i = 1; i <= n; i++)
    {
      sum += 10000 * i;
    }

  printf ("%d\n", sum / n);
  return 0;
}
