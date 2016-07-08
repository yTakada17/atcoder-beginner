#include<stdio.h>

int
main ()
{

  float a = 0, b = 0, c = 0, d = 0;
  scanf ("%f %f %f %f", &a, &b, &c, &d);

  if (b / a > d / c)
    {
      printf ("TAKAHASHI\n");
    }
  else if (b / a < d / c)
    {
      printf ("AOKI\n");
    }
  else
    {
      printf ("DRAW\n");
    }

  return 0;
}
