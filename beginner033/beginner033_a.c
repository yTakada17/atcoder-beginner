#include<stdio.h>

int
main ()
{

  int n = 0;
  int i = 0;

  scanf ("%d", &n);
  for (i = 1; i <= 9; i++)
    {
      if (n % (i * 1111) == 0 || n == 0)
	{
	  printf ("SAME\n");
	  return 0;
	}
    }

  printf ("DIFFERENT\n");
  return 0;
}
