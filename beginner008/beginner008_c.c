#include<stdio.h>
int
main (void)
{
  int i, j, N, C[100], factor[100];
  long double p = 0;
  scanf ("%d\n", &N);
  for (i = 0; i < N; i++)
    factor[i] = -1;
  for (i = 0; i < N; i++)
    scanf ("%d", &C[i]);
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      if (C[i] % C[j] == 0)
	factor[i]++;
  for (i = 0; i < N; i++)
    {
      p += ((factor[i] + 1) / 2) / (double) (factor[i] + 1);
    }
  printf ("%.8Lf\n", N - p);
  return 0;
}
