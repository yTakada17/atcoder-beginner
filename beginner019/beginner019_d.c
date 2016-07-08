#include <stdio.h>

int
main (void)
{
  int i;
  int n;
  int max, maxIdx;

  scanf ("%d", &n);

  max = 0;
  for (i = 2; i <= n; i++)
    {
      int dist;

      printf ("? 1 %d\n", i);
      fflush (stdout);
      scanf ("%d", &dist);

      if (dist > max)
	{
	  max = dist;
	  maxIdx = i;
	}
    }

  max = 0;
  for (i = 1; i <= n; i++)
    if (i != maxIdx)
      {
	int dist;

	printf ("? %d %d\n", maxIdx, i);
	fflush (stdout);
	scanf ("%d", &dist);

	if (dist > max)
	  max = dist;
      }

  printf ("! %d\n", max);

  return 0;
}
