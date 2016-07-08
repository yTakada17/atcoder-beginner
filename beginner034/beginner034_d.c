#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000

int n, k;

int
comp (const void *x, const void *y)
{
  double d = *(double *) x - *(double *) y;
  if (d > 0.0)
    {
      return -1;
    }
  else if (d < 0.0)
    {
      return 1;
    }

  return 0;
}

int
check (double mid, long w[], int p[])
{
  double salt[MAX_N], sum;
  int i;

  for (i = 0; i < n; i++)
    {
      salt[i] = 0.01 * (p[i] - mid) * w[i];
    }
  qsort (salt, n, sizeof (double), comp);

  for (i = 0, sum = 0; i < k; i++)
    {
      sum += salt[i];
    }

  return sum >= 0.0;
}

int
main (void)
{
  long w[MAX_N];
  int p[MAX_N];
  double ok = 0.0, ng = 100.0, mid;
  int i;

  scanf ("%d %d", &n, &k);
  for (i = 0; i < n; i++)
    {
      scanf ("%ld %d", &w[i], &p[i]);
    }

  for (i = 0; i < 100; i++)
    {
      mid = (ok + ng) / 2;
      if (check (mid, w, p))
	{
	  ok = mid;
	}
      else
	{
	  ng = mid;
	}
    }

  printf ("%f\n", mid);

  return 0;
}
