#include<stdio.h>

int
main ()
{
  int n = 0, s = 0, t = 0;
  int w = 0, a = 0;
  int i = 0;
  int count = 0;

  scanf ("%d %d %d", &n, &s, &t);

  for (i = 0; i < n; i++)
    {
      if (i == 0)
	{
	  scanf ("%d", &w);
	}
      else
	{
	  scanf ("%d", &a);
	  w += a;
	}

      if (s <= w && w <= t)
	{
	  count++;
	}
    }

  printf ("%d\n", count);
  return 0;
}
