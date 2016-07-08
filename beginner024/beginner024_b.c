#include <stdio.h>
#define NUM 100000
int
main (void)
{
  int n, t, i, pos = 0;
  int a[NUM];
  scanf ("%d %d", &n, &t);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }

  for (i = 0; i < n - 1; i++)
    {
      if (a[i + 1] - a[i] < t)
	{
	  pos += a[i + 1] - a[i];
	}
      else
	{
	  pos += t;
	}
    }
  pos += t;
  printf ("%d\n", pos);
  return 0;
}
