#include<stdio.h>

int
main ()
{
  int n, i, j;
  scanf ("%d", &n);
  n = 2025 - n;
  for (i = 1; i <= 9; i++)
    {
      for (j = 1; j <= 9; j++)
	{
	  if (i * j == n)
	    {
	      printf ("%d x %d\n", i, j);
	    }
	}
    }
  return 0;
}
