#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int
main ()
{
  float m = 0, n = 0;
  float fm = 0, fn = 0;
  float result = 0;
  scanf ("%f %f", &n, &m);
  if (n > 12)
    {
      n -= 12;
    }

  fn = n * 360 / 12;
  fm = m * 360 / 60;

  result = abs (fn - fm);
  if (result > 180)
    {
      result -= 180;
      printf ("%f\n", result);
    }
  else
    {
      printf ("%f\n", result);
    }

  return 0;
}
