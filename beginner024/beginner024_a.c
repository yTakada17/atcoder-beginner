#include<stdio.h>

int
main ()
{
  int a = 0, b = 0, c = 0, k = 0;
  int s = 0, t = 0;

  scanf ("%d %d %d %d", &a, &b, &c, &k);
  scanf ("%d %d", &s, &t);
  int sum = 0;

  sum += a * s + b * t;
  if (s + t >= k)
    {
      sum -= (s + t) * c;
    }

  printf ("%d\n", sum);

  return 0;
}
