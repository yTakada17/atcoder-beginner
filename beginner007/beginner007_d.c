#include<stdio.h>

#define ll long long

ll
cnt (long long x)
{
  ll res = 0;
  ll tmp = x;
  ll b = 1;
  while (x)
    {
      int t = x % 10;
      x /= 10;
      if (t == 4 || t == 9)
	res = 0;
      res += (t - (t > 4)) * b;
      b *= 8;
    }
  return tmp - res;
}

ll int a, b;
int
main ()
{
  scanf ("%lld %lld", &a, &b);
  printf ("%lld\n", cnt (b + 1) - cnt (a));
  return 0;
}
