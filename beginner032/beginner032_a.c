#include<stdio.h>

int
main ()
{

  int a = 0, b = 0, n = 0;

  scanf ("%d", &a);
  scanf ("%d", &b);
  scanf ("%d", &n);
  while (1)
    {
      if (n % a == 0 && n % b == 0)
	{
	  break;
	}
      n++;
    }
  printf ("%d\n", n);
  return 0;
}
