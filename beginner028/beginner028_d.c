#include<stdio.h>

int
main (void)
{
  long long int n, k;
  unsigned long long int sum;
  double ans;

  scanf ("%lld %lld", &n, &k);

  sum = 1;
  sum = sum + (n - 1) * 3;
  sum = sum + (k - 1) * (n - k) * 6;

  ans = sum * 1.0 / (n * n * n);

  printf ("%1.13lf\n", ans);

  return 0;
}
