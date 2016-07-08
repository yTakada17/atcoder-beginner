#include <stdio.h>

int
main (void)
{
  int i, j, k, l;
  int n, m, x, y;
  int ret, max = 0;
  int select[12]={};
  int relations[12][12]={};

  for (i = 0; i < 12; ++i)
    {
      for (j = 0; j < 12; ++j)
	{
	  relations[i][j] = 0;
	}
    }

  scanf ("%d %d", &n, &m);

  for (i = 0; i < m; ++i)
    {
      scanf ("%d %d", &x, &y);
      x--;
      y--;
      relations[x][y] = 1;
      relations[y][x] = 1;
    }

  for (i = 0; i < (1 << n); ++i)
    {
      int count = 0;

      for (j = 0; j < n; ++j)
	{
	  select[j] = (i >> j) & 1;

	  if (select[j] == 1)
	    {
	      count++;
	    }
	}

      int ok = 1;

      for (k = 0; k < n; ++k)
	{
	  for (l = k + 1; l < n; ++l)
	    {
	      if (select[k] == 1 && select[l] == 1 && relations[k][l] == 0)
		{
		  ok = 0;
		}
	    }
	}

      if (ok == 1)
	{
	  ret = count;

	  if (ret > max)
	    {
	      max = ret;
	    }
	}
    }

  printf ("%d\n", max);

  return 0;
}
