#include <stdio.h>

int
main ()
{
  int N, C[30000];
  int i, j, max;
  int cnt[30000] = { 0 };

  scanf ("%d\n", &N);
  for (i = 0; i < N; i++)
    {
      scanf ("%d\n", &C[i]);
      max = 0;
      for (j = C[i] - 1; j >= 0; j--)
	if (cnt[j] > max)
	  max = cnt[j];
      cnt[C[i] - 1] = max + 1;
    }
  for (i = 0, j = 0; i < N; i++)
    if (cnt[i] > j)
      j = cnt[i];


  printf ("%d\n", N - j);
  return 0;
}
