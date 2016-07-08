#include<stdio.h>

int
main ()
{
  long n, h, a, b, c, d, e, x, y, damage, money;
  scanf ("%ld %ld", &n, &h);
  scanf ("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e);

  damage = e * n - h;
  b += e;
  d += e;
  y = damage / d + 1;

  if (damage < 0)
    {
      y = 0;
    }
  x = 0;
  money = a * x + c * y;

  while (y > 0)
    {
      x++;
      while ((b * x + d * y > damage) && (y >= 0))
	{
	  y--;
	}
      y++;
      if (a * x + c * y < money)
	{
	  money = a * x + c * y;
	}
    }
  if (money < 0)
    {
      money = 0;
    }
  printf ("%ld\n", money);
  return 0;
}
