#include <stdio.h>
int
max (int a, int b)
{
  if (a < b)
    return b;
  else
    return a;
}

int
min (int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}

int
main ()
{
  int n;
  int b[21];
  int i, j;
  int t[21] = { 0 };
  int max_t, min_t;
  int flag = 0;
  scanf ("%d", &n);
  for (i = 2; i <= n; i++)
    scanf ("%d", &b[i]);

  t[n] = 1;
  for (i = n - 1; i >= 1; i--)
    {
      max_t = 0;
      min_t = 10000000;
      flag = 0;
      for (j = i + 1; j <= n; j++)
	{
	  if (b[j] == i)
	    {
	      flag = 1;
	      max_t = max (max_t, t[j]);
	      min_t = min (min_t, t[j]);
	    }
	}
      if (flag == 1)
	t[i] = max_t + min_t + 1;
      else
	t[i] = 1;

    }

  printf ("%d\n", t[1]);
  return 0;
}
