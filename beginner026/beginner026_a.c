#include<stdio.h>

int
main ()
{
  int a = 0;
  int i = 0;
  int max = 0;

  scanf ("%d", &a);
  for (i = 0; i < a; i++)
    {
      if (max < i * (a - i))
	{
	  max = i * (a - i);
	}
    }
  printf ("%d\n", max);
  return 0;
}
