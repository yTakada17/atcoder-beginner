#include <stdio.h>
#define MOD 1000000007

int r, c, x, y, d, l;

long long
mod_pow (int a, int b)
{
  long long i, j, k;
  long long ans = 1;

  if (a * b < d + l || a <= 0 || b <= 0)
    {
      return 0;
    }
  for (i = a * b, j = 0; j < d + l; i--, j++)
    {
      ans = (ans * i) % MOD;
    }
  for (i = d; i > 0; i--)
    {
      for (j = 0, k = i; (1 << j) < MOD - 2; j++)
	{
	  if ((MOD - 2 >> j) & 1)
	    {
	      ans = (ans * k) % MOD;
	    }
	  k = (k * k) % MOD;
	}
    }
  for (i = l; i > 0; i--)
    {
      for (j = 0, k = i; (1 << j) < MOD - 2; j++)
	{
	  if ((MOD - 2 >> j) & 1)
	    {
	      ans = (ans * k) % MOD;
	    }
	  k = (k * k) % MOD;
	}
    }

  return ans;
}

int
main (void)
{
  long long ans = 1;

  scanf ("%d %d", &r, &c);
  scanf ("%d %d", &x, &y);
  scanf ("%d %d", &d, &l);

  ans = mod_pow (x, y);
  ans =
    (ans - mod_pow (x - 1, y) * 2 - mod_pow (x, y - 1) * 2 + MOD * 4LL) % MOD;
  ans =
    (ans + mod_pow (x - 1, y - 1) * 4 + mod_pow (x - 2, y) +
     mod_pow (x, y - 2)) % MOD;
  ans =
    (ans - mod_pow (x - 1, y - 2) * 2 - mod_pow (x - 2, y - 1) * 2 +
     MOD * 4LL) % MOD;
  ans = (ans + mod_pow (x - 2, y - 2)) % MOD;

  ans = (ans * (r - x + 1)) % MOD;
  ans = (ans * (c - y + 1)) % MOD;

  printf ("%lld\n", ans);

  return 0;
}
