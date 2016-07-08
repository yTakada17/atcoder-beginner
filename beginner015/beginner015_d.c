#include <stdio.h>

#define	max(A, B) ((A > B)? A : B)

int dp[10001][51];

int
main ()
{
  int i, j;
  int W, K, N;
  int w, v;
  scanf ("%d", &W);
  scanf ("%d %d", &N, &K);

  while (N--)
    {
      scanf ("%d %d", &w, &v);
      for (j = K; j > 0; j--)
	{
	  for (i = w; i <= W; i++)
	    {
	      dp[i][j] = max (dp[i][j], dp[i - w][j - 1] + v);
	    }
	}
    }
  printf ("%d\n", dp[W][K]);

  return 0;
}
