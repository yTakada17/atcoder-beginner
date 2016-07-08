#include<stdio.h>

int
main ()
{

  int i1 = 0, i2 = 0, i3 = 0;

  scanf ("%d %d %d", &i1, &i2, &i3);
  if (i1 == i2)
    {
      printf ("%d\n", i3);
    }
  else
    {
      if (i1 == i3)
	{
	  printf ("%d\n", i2);
	}
    }

  return 0;
}
