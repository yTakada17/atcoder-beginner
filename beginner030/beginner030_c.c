#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  int n, m, x, y, *a, *b;
  int i, j, b_now = 0;
  int count = 0;
  int now = 0;

  scanf ("%d %d %d %d", &n, &m, &x, &y);
  a = malloc (sizeof (int) * n);
  b = malloc (sizeof (int) * m);
  for (i = 0; i < n; i++)
    scanf ("%d", &a[i]);
  for (j = 0; j < m; j++)
    scanf ("%d", &b[j]);



  for (i = 0; i < n; i++)
    {
      if (a[i] >= now)
	{
	  now = a[i] + x;

	  for (j = b_now; j < m; j++)
	    {
	      if (b[j] >= now)
		{
		  now = b[j] + y;
		  count++;
		  b_now = j;
		  break;
		}
	    }
	}
    }

  printf ("%d\n", count);

  return 0;
}
