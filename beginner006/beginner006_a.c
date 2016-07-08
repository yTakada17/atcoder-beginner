#include<stdio.h>

int
main ()
{
  int n = 0;
  scanf ("%d", &n);

  if (n == 3 || n == 6 || n == 9)
    {
      printf ("YES\n");
    }
  else
    {
      printf ("NO\n");
    }
  return 0;
}
