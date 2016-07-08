#include <stdio.h>

int
main ()
{
  int imos[100002] = { 0 };
  int n, m, l, r, s, i;
  int sum = 0, min;

  scanf ("%d %d", &n, &m);

  for (i = 0; i < n; i++)
    {
      scanf ("%d %d %d", &l, &r, &s);
      sum += s;
      imos[l] += s;
      imos[r + 1] -= s;
    }

  for (i = 1; i <= m; i++)
    {
      imos[i] += imos[i - 1];
    }

  min = imos[1];
  for (i = 2; i <= m; i++)
    {
      if (min > imos[i])
	{
	  min = imos[i];
	}
    }

  printf ("%d\n", sum - min);

  return 0;
}
