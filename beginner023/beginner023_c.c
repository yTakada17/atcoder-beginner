#include <stdio.h>

int
nextInt (void)
{
  char ch;
  int sign, x;

  do
    {
      ch = getchar ();
    }
  while (ch < '-');

  if (ch == '-')
    {
      sign = -1;
      ch = getchar ();
    }
  else
    sign = 1;

  x = 0;
  while (ch >= '0' && ch <= '9')
    {
      x = x * 10 + ch - '0';
      ch = getchar ();
    }

  return sign * x;
}

int r[100000], c[100000];
int sum_r[100000], sum_c[100000];
int cnt_r[100001], cnt_c[100001];

int
main (void)
{
  int i;
  int R, C, k, n;
  long long ans;

  scanf ("%d %d %d %d", &R, &C, &k, &n);
  for (i = 0; i < n; i++)
    {
      r[i] = nextInt () - 1;
      c[i] = nextInt () - 1;
      sum_r[r[i]]++;
      sum_c[c[i]]++;
    }

  for (i = 0; i < R; i++)
    cnt_r[sum_r[i]]++;
  for (i = 0; i < C; i++)
    cnt_c[sum_c[i]]++;

  ans = 0;
  for (i = 0; i <= k; i++)
    ans += cnt_r[i] * cnt_c[k - i];
  for (i = 0; i < n; i++)
    {
      if (sum_r[r[i]] + sum_c[c[i]] == k)
	ans--;
      if (sum_r[r[i]] + sum_c[c[i]] == k + 1)
	ans++;
    }

  printf ("%lld\n", ans);

  return 0;
}
