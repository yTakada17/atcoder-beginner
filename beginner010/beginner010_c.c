#include <stdio.h>
#include <math.h>

int
main ()
{
  int tx1, ty1, tx2, ty2, t, v, n;
  int x, y, i;
  float dis1, dis2;

  scanf ("%d %d %d %d %d %d", &tx1, &ty1, &tx2, &ty2, &t, &v);
  scanf ("%d", &n);

  for (i = 0; i < n; i++)
    {
      scanf ("%d %d", &x, &y);
      dis1 = sqrt ((float) ((x - tx1) * (x - tx1) + (y - ty1) * (y - ty1)));
      dis2 = sqrt ((float) ((x - tx2) * (x - tx2) + (y - ty2) * (y - ty2)));

      if (t * v >= dis1 + dis2)
	{
	  printf ("YES\n");
	  return 0;
	}
    }

  printf ("NO\n");

  return 0;
}
