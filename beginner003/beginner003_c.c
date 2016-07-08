#include <stdio.h>
#include <stdlib.h>

void
sort (int *a, int n)
{
  int i;
  for (i = 1; i < n; i++)
    {
      int j;
      int tmp = a[i];
      for (j = i; j > 0 && a[j - 1] > tmp; j--)
	a[j] = a[j - 1];
      a[j] = tmp;
    }
}

int
main (void)
{
  double maxrate = 0.0;
  int n, k, i;
  scanf ("%d %d", &n, &k);
  int rate[n];
  for (i = 0; i < n; i++)
    scanf ("%d", &rate[i]);

  sort (rate, n);
  if (k == 1)
    maxrate = (double) rate[n - 1] / 2.0;
  else
    {
      for (i = n - k; i < n; i++)
	{
	  maxrate = (maxrate + (double) rate[i]) / 2.0;
	}
    }
  printf ("%.6f\n", maxrate);
  return 0;
}
