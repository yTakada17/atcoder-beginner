#include <stdio.h>
#include <string.h>


int
main ()
{
  int n, i, j, max = 0, maxind = 0, point[50] = { };
  char chiket[50][51];
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%s", chiket[i]);
    }
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  if (strcmp (chiket[i], chiket[j]) == 0)
	    {
	      point[i]++;
	    }
	}
    }

  for (i = 0; i < n; i++)
    {
      if (max < point[i])
	{
	  max = point[i];
	  maxind = i;
	}
    }
  printf ("%s\n", chiket[maxind]);
  return 0;
}
