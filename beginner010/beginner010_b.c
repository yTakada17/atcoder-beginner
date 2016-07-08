#include <stdio.h>

int
main (void)
{
  int n, res, buff, i;

  scanf ("%d", &n);

  res = 0;

  for (i = 0; i < n; i++)
    {
      scanf ("%d", &buff);
      switch (buff % 6)
	{
	case 0:
	  res += 3;
	  break;
	case 2:
	  res += 1;
	  break;
	case 4:
	  res += 1;
	  break;
	case 5:
	  res += 2;
	  break;
	}
    }

  printf ("%d\n", res);

  return 0;
}
