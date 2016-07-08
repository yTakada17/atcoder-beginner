#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int
main ()
{
  int i, j;
  int N, M, D;
  int T[200001];
  int out[200001];
  int T_out[200001];
  int T_tmp[200001];
  int A;
  int tmp;

  scanf ("%d %d %d", &N, &M, &D);
  for (i = 1; i <= N; i++)
    {
      T[i] = i;
      out[i]=i;
    }

  for (i = 1; i <= M; i++)
    {
      scanf ("%d", &A);
      tmp = T[A];
      T[A] = T[A + 1];
      T[A + 1] = tmp;
    }
  for (i = 1; i <= N; i++)
    {
      T_out[i] = T[i];
    }
  for (i = 1; i <= N; i++)
    {
      T[T_out[i]] = i;
    }

  while (D > 0)
    {
      for (j = 1; j <= N; j++)
	{
	  T_out[j] = j;
	}
      for (j = 1; j <= N; j++)
	{
	  T_out[j] = T_tmp[j] = T[T_out[j]];
	}

      i = 1;
      while (i * 2 <= D)
	{
	  i = i * 2;
	  for (j = 1; j <= N; j++)
	    {
	      T_out[j] = T_tmp[T_out[j]];
	    }
	  for (j = 1; j <= N; j++)
	    {
	      T_tmp[j] = T_out[j];
	    }
	}
      for (j = 1; j <= N; j++)
	{
	  out[j] = T_out[out[j]];
	}
      D -= i;
    }

  for (i = 1; i <= N; i++)
    {
      printf ("%d\n", out[i]);
    }
  return 0;
}
