#include<stdio.h>
#define SIZE 50

int
main ()
{
  int l = 0, h = 0;
  int n = 0;
  int a[SIZE] = { };
  int i = 0;

  scanf ("%d %d", &l, &h);
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }

  for (i = 0; i < n; i++)
    {
      if (a[i] < l)
	{
	  a[i] = l - a[i];
	}
      else if (l < a[i] && a[i] < h)
	{
	  a[i] = 0;
	}
      else
	{
	  a[i] = -1;
	}
    }

  for (i = 0; i < n; i++)
    {
      printf ("%d\n", a[i]);
    }

  return 0;
}
