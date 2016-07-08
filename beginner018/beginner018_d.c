#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int happy[18][18] = { 0 };

int max = 0;
int
comp (const void *c1, const void *c2)
{
  int tmp1 = *(int *) c1;
  int tmp2 = *(int *) c2;

  if (tmp1 < tmp2)
    return 1;
  if (tmp1 == tmp2)
    return 0;
  if (tmp1 > tmp2)
    return -1;
}

void
combi (int N, int M, int P, int Q, int n, int *pre)
{
  int i;
  int manPoint[18] = { 0 };

  for (i = 0; i < M; i++)
    manPoint[i] += happy[n][i] + pre[i];
  for (i = n + 1; i < N; i++)
    if (P > 1)
      combi (N, M, P - 1, Q, i, manPoint);
  qsort (manPoint, 18, sizeof (int), comp);
  int nowmax = 0;
  for (i = 0; i < Q; ++i)
    {
      nowmax += manPoint[i];
    }
  if (max < nowmax)
    max = nowmax;
}

int
main ()
{
  int N, M, P, Q, R;

  scanf ("%d %d %d %d %d", &N, &M, &P, &Q, &R);
  int i, x, y, z, point;

  for (i = 0; i < R; i++)
    {
      scanf ("%d %d %d", &x, &y, &z);
      happy[x - 1][y - 1] = z;
    }
  int manPoint[18] = { 0 };
  for (i = 0; i < N; i++)
    {
      if (N - i > P - 1)
	combi (N, M, P, Q, i, manPoint);
    }
  printf ("%d\n", max);

  return 0;
}
