#include <stdio.h>
#include <math.h>
double pi = 3.141592653589;
int a, b, c;
double
f (double x)
{
  return a * x + b * sin (c * x * pi);
}

double
df (double x)
{
  return a + b * c * pi * cos (c * x * pi);
}

int
main ()
{
  int i;
  double x = 0;
  double min = 0, max = 1000;
  double epsilon = 1e-10;

  scanf ("%d %d %d", &a, &b, &c);
  for (i = 0; i < 1000; i++)
    {
      x = (min + max) / 2;
      if (f (x) < 100)
	min = x;
      else
	max = x;

      if (fabs (f (x) - 100) < epsilon)
	break;
    }
  printf ("%.15f\n", min);
  return 0;
}
