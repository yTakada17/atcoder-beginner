#include <stdio.h>

int
main ()
{
  int N;
  int a, b;
  int K;
  int P[100];
  int i, j;

  scanf ("%d", &N);
  scanf ("%d %d", &a, &b);
  scanf ("%d", &K);
  for (i = 0; i < K; i++)
    {
      scanf ("%d", &P[i]);
      for (j = 0; j < i; j++)
	{
	  if (P[i] == P[j])
	    {
	      printf ("NO\n");
	      return 0;
	    }
	}
    }

  for (i = 0; i < K; i++)
    {
      if (a == P[i] || b == P[i])
	{
	  printf ("NO\n");
	  return 0;
	}
    }

  printf ("YES\n");

  return 0;
}
