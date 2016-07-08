#include<stdio.h>

int
main ()
{
  int a = 0, b = 0, c = 1, n;
  scanf ("%d", &n);
  n--;
  if (n < 3)
    printf ("%d\n", n / 2);
  else
    {
      int i, x;
      for (i = 0; i < n - 2; i++)
	{
	  x = a;
	  a = b;
	  b = c;
	  c = (x + a + b) % 10007;
	}
      printf ("%d\n", c);
    }
  return 0;
}
