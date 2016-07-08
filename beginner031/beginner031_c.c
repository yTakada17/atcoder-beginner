#include <stdio.h>

int a[55];
int
score (int who, int l, int h)
{				// who 0->t 1->a
  int res = 0;
  if (h < l)
    return score (who, h, l);
  for (l += who; l <= h; l += 2)
    res += a[l];
  return res;
}

int
main ()
{
  int n, i, j, aj, t, amax, tmax = -5000;
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", a + i);
    }
  for (i = n - 1; 0 <= i; i--)
    {
      amax = -5000;
      for (j = n - 1; 0 <= j; j--)
	{
	  if (j == i)
	    continue;
	  t = score (1, i, j);
	  if (amax <= t)
	    {
	      amax = t;
	      aj = j;
	    }
	  //printf("a%d %d %d\n",i,j,t);
	}
      t = score (0, i, aj);
      //printf("t%d %d %d\n",i,aj,t);
      tmax = tmax < t ? t : tmax;
    }
  printf ("%d\n", tmax);
  return 0;
}
