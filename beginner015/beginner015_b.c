#include <stdio.h>
int
main ()
{
  int N, n = 0, ans, i, A[100];
  double bug = 0.0;

  scanf ("%d", &N);
  for (i = 0; i < N; i++)
    {
      scanf ("%d", &A[i]);
      bug += A[i];
      if (A[i] != 0)
	n++;
    }
  ans = bug / n * 10;

  if (ans % 10 == 0)
    {
      printf ("%d", ans / 10);
    }
  else
    {
      printf ("%d", ans / 10 + 1);
    }

  return 0;
}
