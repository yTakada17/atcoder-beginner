#include<stdio.h>

int
main ()
{

  double x1, y1, x2, y2, x3, y3, x4, y4;
  double f, f1;
  double a, b, a1, b1;
  int count = 0, n, i;

  scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
  scanf ("%d", &n);
  scanf ("%lf%lf%lf%lf", &x3, &y3, &x4, &y4);
  f = x3;
  f1 = y3;

  for (i = 0; i < n; i++)
    {

      a = (x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3);
      b = (x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4);

      a1 = (x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1);
      b1 = (x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2);


      if (a * b < 0 && a1 * b1 < 0)
	count++;
      x3 = x4;
      y3 = y4;


      if (i != n - 2 && i != n - 1)
	scanf ("%lf%lf", &x4, &y4);
      if (i == n - 2)
	{
	  x4 = f;
	  y4 = f1;
	}

    }

  printf ("%d\n", (count + 2 + 1) / 2);

  return 0;

}
