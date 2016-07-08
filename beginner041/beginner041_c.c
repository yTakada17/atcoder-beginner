#include<stdio.h>
#define N 10000+1

int
main ()
{
  int n = 0;
  int a[N][2] = { };
  a[0][1] = 1;
  int i = 0, j = 0;

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i][0]);
      a[i + 1][1] = a[i][1] + 1;
    }

  for (i = 0; i < n; i++)
    {
      for (j = n - 1; j > i; j--)
	{
	  if (a[j][0] > a[j - 1][0])
	    {
	      int tmp = a[j][0];
	      a[j][0] = a[j - 1][0];
	      a[j - 1][0] = tmp;

	      tmp = a[j][1];
	      a[j][1] = a[j - 1][1];
	      a[j - 1][1] = tmp;
	    }
	}
    }

  for (i = 0; i < n; i++)
    {
      printf ("%d\n", a[i][1]);
    }

  return 0;
}
