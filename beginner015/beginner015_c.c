#include<stdio.h>
#include<string.h>

int T[5][5];
int N, K;
int flag = 0;
void
C (int n, int num)
{
  int i;
  if (n == N - 1)
    {
      if (num == 0)
	{
	  flag = 1;
	}
    }
  else
    {
      if (flag == 0)
	{
	  for (i = 0; i < K; ++i)
	    {

	      C (n + 1, num ^ T[n + 1][i]);
	    }
	}
    }
}

int
main ()
{
  scanf ("%d %d", &N, &K);
  int i, j;
  for (i = 0; i < N; ++i)
    {
      for (j = 0; j < K; ++j)
	{
	  scanf ("%d", &T[i][j]);
	}
    }
  for (i = 0; i < K; ++i)
    {
      C (0, T[0][i]);
    }
  if (flag == 1)
    printf ("Found\n");
  else if (flag == 0)
    printf ("Nothing\n");

  return 0;
}
