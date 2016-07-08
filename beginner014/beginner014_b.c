#include <stdio.h>
int
main (void)
{
  int x, n;
  int i;
  int a;
  int k = 0;
  int hako[20];
  scanf ("%d %d", &n, &x);
  for (i = 0; i <= n - 1; i++)
    {
      scanf ("%d", &a);
      hako[i] = a;
    }
  for (i = 0; i <= n - 1; i++)
    {
      if (x % 2)
	{
	  k += hako[i];
	}
      x = x / 2;
    }
  printf ("%d\n", k);
  return (0);
}
