#include <stdio.h>

int mod = 1000000007, dp[1 << 25], x[25], a[26];

int
check (int n)
{
  if (n % 5 != 0 && n % 5 != 4)
    {
      if (x[n - 1] <= 0 && x[n + 1] > 0)
	{
	  return -1;
	}
      if (x[n - 1] > 0 && x[n + 1] <= 0)
	{
	  return -1;
	}
    }
  if (n / 5 != 0 && n / 5 != 4)
    {
      if (x[n - 5] <= 0 && x[n + 5] > 0)
	{
	  return -1;
	}
      if (x[n - 5] > 0 && x[n + 5] <= 0)
	{
	  return -1;
	}
    }
  return 0;
}

int
f (int n, int p)
{
  int i;

  if (dp[p] != -1)
    {
      return dp[p];
    }
  else if (n == 26)
    {
      dp[p] = 1;
      return dp[p];
    }
  else if (a[n] != -1)
    {
      dp[p] = 0;
      x[a[n]] = n;
      if (check (a[n]) == 0)
	{
	  dp[p] = f (n + 1, p + (1 << a[n]));
	}
      x[a[n]] = -1;
      return dp[p];
    }
  else
    {
      dp[p] = 0;
      for (i = 0; i < 25; i++)
	{
	  if (x[i] == 0)
	    {
	      x[i] = n;
	      if (check (i) == 0)
		{
		  dp[p] += f (n + 1, p + (1 << i));
		  dp[p] %= mod;
		}
	      x[i] = 0;
	    }
	}
      return dp[p];
    }
}

int
main ()
{
  int i, j, sum = 0, ip = 0;

  for (i = 0; i < 25; i++)
    {
      scanf ("%d", &x[i]);
    }

  for (i = 0; i < (1 << 25); i++)
    {
      dp[i] = -1;
    }

  for (i = 0; i < 25; i++)
    {
      for (j = 0; j < 25; j++)
	{
	  if (x[j] == i + 1)
	    {
	      a[i + 1] = j;
	      x[j] = -1;
	      j = 25;
	    }
	  else if (j == 24)
	    {
	      a[i + 1] = -1;
	    }
	}
    }

  printf ("%d\n", f (1, 0));
  return 0;
}
