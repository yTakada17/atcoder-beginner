#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int
main ()
{
  int xa = 0, xb = 0, xc = 0;
  int ya = 0, yb = 0, yc = 0;
  int tmp = 0;

  scanf ("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);

  if (xa != 0 || ya != 0)
    {
      tmp = xa;
      xa = xa - abs (xa);
      xb = xb - abs (tmp);
      xc = xc - abs (tmp);
      if (xa != 0)
	{
	  xb = xb + 2 * abs (tmp);
	  xc = xc + 2 * abs (tmp);
	}

      tmp = ya;
      ya = ya - abs (ya);
      yb = yb - abs (tmp);
      yc = yc - abs (tmp);
      if (ya != 0)
	{
	  yb = yb + 2 * abs (tmp);
	  yc = yc + 2 * abs (tmp);
	}
    }

  printf ("%.1f\n", (double) abs (xb * yc - yb * xc) / 2);
  return 0;
}
