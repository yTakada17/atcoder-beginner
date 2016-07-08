#include <stdio.h>

int
main (void)
{
  int n, i, buff;
  int max, nd;

  scanf ("%d", &n);

  for (i = 0; i < n; i++)
    {
      scanf ("%d", &buff);

      if (max < buff)
	{
	  nd = max;
	  max = buff;
	}
      else if (max == buff)
	{
	  continue;
	}
      else if (nd < buff)
	{
	  nd = buff;
	}
    }

  printf ("%d\n", nd);

  return 0;
}
