#include <stdio.h>
int X[2000], Y[2000], D[2000][2000];

int
main ()
{
  int a, b, c, i, j, k, m, N, T[3] = { 0, 0, 0 };
  scanf ("%d", &N);
  for (i = 0; i < N; i++)
    {
      scanf ("%d%d", &X[i], &Y[i]);
    }

  for (i = 0; i < N; i++)
    {
      for (j = 0; j < i; j++)
	{
	  D[i][j] =
	    (X[j] - X[i]) * (X[j] - X[i]) + (Y[j] - Y[i]) * (Y[j] - Y[i]);
	}
    }

  for (i = 0; i < N; i++)
    {
      for (j = 0; j < i; j++)
	{
	  for (k = 0; k < j; k++)
	    {
	      a = D[i][j];
	      b = D[j][k];
	      c = D[i][k];
	      m = a;
	      if (m < b)
		m = b;
	      if (m < c)
		m = c;
	      m = a + b + c - m - m;
	      T[0] += (m > 0);
	      T[1] += (m == 0);
	      T[2] += (m < 0);
	    }
	}
    }

  printf ("%d %d %d\n", T[0], T[1], T[2]);

  return 0;
}
