#include<stdio.h>
#define SIZE 100

int
main ()
{

  int n = 0;
  int ary[SIZE] = { };
  int i = 0;
  int min = 0;

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &ary[i]);
    }

  min = ary[0];
  for (i = 0; i < n; i++)
    {
      if (min > ary[i])
	{
	  min = ary[i];
	}
    }

  printf ("%d\n", min);

  return 0;
}
