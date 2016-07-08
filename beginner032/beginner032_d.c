#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
long int W;
long int v[200], w[200];
long long int dp[201][200001];
typedef struct
{
  long long int v;
  long long int w;
} comb;
comb dp1[1 << 15], dp2[1 << 15];

long long int max (long long int a, long long int b);
long long int min (long long int a, long long int b);
void solve ();
void solve_v ();
void solve_w ();
int vcmp (const void *a, const void *b);
int wcmp (const void *a, const void *b);

int
main ()
{
  int f = 0, f1 = 0, f2 = 0, i;
  scanf ("%d%ld", &N, &W);
  for (i = 0; i < N; i++)
    {
      scanf ("%ld%ld", &v[i], &w[i]);
      if (!f && (v[i] <= 1000 || w[i] <= 1000))
	{
	  if (w[i] <= 1000)
	    f1 = 1;
	  else
	    f1 = 0;
	  if (v[i] <= 1000)
	    f2 = 1;
	  else
	    f2 = 0;
	}
      else
	f = 1;
    }

  if (f)
    {				// dataset 1 
      solve ();
    }
  else if (!f && f1)
    {				// dataset 2
      solve_w ();
    }
  else
    {				// dataset 3
      solve_v ();
    }

  return 0;
}

void
solve ()
{
  int i, j;
  long int h, l, mid, m1 = 1 << (N / 2), m2 = 1 << (N - N / 2);
  memset (dp1, 0, sizeof (dp1));
  memset (dp2, 0, sizeof (dp2));
  for (i = 0; i < m1; i++)
    {
      for (j = 0; j < N / 2; j++)
	{
	  if (i & (1 << j))
	    {
	      dp1[i].v += v[j];
	      dp1[i].w += w[j];
	    }
	}
    }
  for (i = 0; i < m2; i++)
    {
      for (j = N / 2; j < N; j++)
	{
	  if (i & (1 << j - N / 2))
	    {
	      dp2[i].v += v[j];
	      dp2[i].w += w[j];
	    }
	}
    }
  qsort (dp1, m1, sizeof (comb), wcmp);

  for (i = 1; i < m1; i++)
    {
      if (dp1[i - 1].v >= dp1[i].v || dp1[i].w > W)
	{
	  for (j = i; j < m1 - 1; j++)
	    {
	      dp1[j] = dp1[j + 1];
	    }
	  memset (&dp1[(m1--) - 1], 0, sizeof (comb));
	  i--;
	}
    }

  for (i = 0; i < m2; i++)
    {
      if (dp2[i].w > W)
	{
	  dp2[i].v = 0;
	  dp2[i].w = 0;
	  continue;
	}
      l = 0;
      h = m1 - 1;
      do
	{
	  mid = l + (h - l) / 2;
	  if (dp1[mid].w == W - dp2[i].w)
	    {
	      l = mid;
	      h = mid;
	    }
	  else if (dp1[mid].w > W - dp2[i].w)
	    {
	      if (dp1[mid - 1].w <= W - dp2[i].w)
		{
		  l = (--mid);
		  h = mid;
		}
	      else
		h = max (mid - 1, 0);
	    }
	  else
	    {
	      l = min (mid + 1, h);
	    }
	}
      while (l != mid || mid != h);
      dp2[i].v += dp1[mid].v;
      dp2[i].w += dp1[mid].w;
    }
  qsort (dp2, m2, sizeof (comb), vcmp);

  printf ("%lld\n", dp2[0].v);
}

void
solve_v ()
{
  long int i, j, Y = 0;
  long long int tv = 0, tw = 0;
  for (i = 0; i < N; i++)
    {
      tv += v[i];
      tw += w[i];
    }
  dp[0][0] = 0;
  for (j = 1; j <= tv + 1; j++)
    {
      dp[0][j] = tw + 1;
    }
  for (i = 1; i <= N; i++)
    {
      for (j = 0; j <= tv + 1; j++)
	{
	  if (j < v[i - 1])
	    dp[i][j] = dp[i - 1][j];
	  else
	    dp[i][j] = min (dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
	}
    }
  for (i = 1; i <= N; i++)
    {
      for (j = 0; j <= tv + 1; j++)
	{
	  if (Y < j && dp[i][j] <= W)
	    Y = j;
	}
    }
  printf ("%ld\n", Y);
}

void
solve_w ()
{
  int i, j;
  for (j = 0; j <= W; j++)
    {
      dp[0][j] = 0;
    }
  for (i = 1; i <= N; i++)
    {
      for (j = 0; j <= W; j++)
	{
	  if (j < w[i - 1])
	    dp[i][j] = dp[i - 1][j];
	  else
	    dp[i][j] = max (dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
	}
    }
  printf ("%lld\n", dp[N][W]);
}

long long int
max (long long int a, long long int b)
{
  return (a < b) ? b : a;
}

long long int
min (long long int a, long long int b)
{
  return (a < b) ? a : b;
}

int
vcmp (const void *a, const void *b)
{
  comb x = *(comb *) a;
  comb y = *(comb *) b;
  if (y.v - x.v > 0)
    return 1;
  else if (y.v - x.v == 0)
    return 0;
  else
    return -1;
}

int
wcmp (const void *a, const void *b)
{
  comb x = *(comb *) a;
  comb y = *(comb *) b;
  if (x.w - y.w > 0)
    return 1;
  else if (x.w - y.w == 0)
    return 0;
  else
    return -1;
}
