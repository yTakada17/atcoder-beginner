#include<stdio.h>

int
main ()
{
int N,M;
int ga[400][400]={{0}};
int max=0,ans=1000000;
  int i, j, k, a, b, t;
  scanf ("%d %d", &N, &M);

  for (i = 1; i <= N; i++)
    {
      for (j = 1; j <= N; j++)
	{
	  if (i != j)
	    {
	      ga[i][j] = 10000000;
	    }
	}
    }
  for (i = 0; i < M; i++)
    {
      scanf ("%d %d %d", &a, &b, &t);
      ga[a][b] = ga[b][a] = t;
    }

  for (k = 1; k <= N; k++)
    {
      for (i = 1; i <= N; i++)
	{
	  for (j = 1; j <= N; j++)
	    {
	      ga[i][j] =
		ga[i][j] <
		(ga[i][k] + ga[k][j]) ? ga[i][j] : (ga[i][k] + ga[k][j]);
	    }
	}
    }
  for (i = 1; i <= N; i++)
    {
      max = 0;
      for (j = 1; j <= N; j++)
	{
	  if (i != j)
	    {
	      max = max > ga[i][j] ? max : ga[i][j];
	    }
	}
	  ans = ans < max ? ans : max;
    }
  printf ("%d\n", ans);
  return 0;
}
