#include <stdio.h>

int nurikata = 0;
int cumsum[501][501] = { 0 };

int
main (void)
{
  int R, C, K;
  int x, y, k, sum;
  scanf ("%d%d%d\n", &R, &C, &K);
  for (x = 1; x <= R; x++)
    {
      for (y = 1; y <= C; y++)
	{
	  int ispeke = getchar () == 'x';
	  cumsum[x][y] = ispeke + cumsum[x][y - 1];
	}
      getchar ();
    }
  for (x = K; x <= R - K + 1; x++)
    {
      for (y = K; y <= C - K + 1; y++)
	{
	  for (k = 0; k <= K - 1; k++)
	    {
	      int x0 = x - k;
	      int x1 = x + k;
	      int y0 = y - (K - 1 - k);
	      int y1 = y + (K - 1 - k);
	      if (cumsum[x0][y1] - cumsum[x0][y0 - 1])
		break;
	      if (cumsum[x1][y1] - cumsum[x1][y0 - 1])
		break;
	    }
	  if (k == K)
	    nurikata++;
	}
    }
  printf ("%d\n", nurikata);
  return 0;
}
