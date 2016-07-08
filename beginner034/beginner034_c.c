#include <stdio.h>
#define MAX(i,j) (i >= j ? i : j)
#define MIN(i,j) (i <= j ? i : j)
#define MOD 1000000007

int
main (void)
{
  long w, h, i, j;
  long long ans = 1, n;

  scanf ("%ld %ld", &w, &h);

  for (i = w + h - 2; i >= MAX (w, h); i--)
    {
      ans = (ans * i) % MOD;
    }
  for (i = MIN (w, h) - 1; i > 0; i--)
    {
      for (j = 0, n = i; (MOD - 2 >> j) > 0; j++)
	{
	  if ((MOD - 2 >> j) & 1)
	    {
	      ans = (ans * n) % MOD;
	    }
	  n = (n * n) % MOD;
	}
    }

  printf ("%lld\n", ans);

  return 0;
}
