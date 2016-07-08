#include <stdio.h>
#define POS_MAX 900
#define MAR_MAX 900
#define COST_MAX 1000000
#define MIN(x,y) (x <= y ? x : y)
#define ABS(i) ((i) >= 0 ? (i) : (-1) * (i))

int r, g, b;
long cost[POS_MAX + 1][MAR_MAX + 1];

long
solve (int i, int j)
{
  int c;

  if (cost[i][j] < COST_MAX)
    {
      return cost[i][j];
    }

  if (POS_MAX - i < j)
    {
      cost[i][j] = COST_MAX;
    }
  else if (j == 1)
    {
      if (i == POS_MAX)
	{
	  cost[i][j] = ABS (i - 550);
	}
      else
	{
	  cost[i][j] = MIN (ABS (i - 550), solve (i + 1, j));
	}
    }
  else
    {
      if (j <= b)
	{
	  c = ABS (i - 550);
	}
      else if (j <= b + g)
	{
	  c = ABS (i - 450);
	}
      else
	{
	  c = ABS (i - 350);
	}
      cost[i][j] = MIN (solve (i + 1, j - 1) + c, solve (i + 1, j));
    }

  return cost[i][j];
}

int
main (void)
{
  int i, j, c;
  scanf ("%d %d %d", &r, &g, &b);

  for (i = 0; i <= POS_MAX; i++)
    {
      for (j = 0; j <= MAR_MAX; j++)
	{
	  cost[i][j] = COST_MAX;
	}
    }

  printf ("%ld\n", solve (0, r + g + b));

  return 0;
}
