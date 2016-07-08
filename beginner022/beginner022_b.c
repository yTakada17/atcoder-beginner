#include<stdio.h>

int
main (void)
{
  int num[100000];
  int visit[100001] = { 0 };
  int i, N;
  int ans = 0;

  scanf ("%d", &N);

  for (i = 0; i < N; i++)
    {
      scanf ("%d", &num[i]);
    }

  for (i = 0; i < N; i++)
    {
      visit[num[i]]++;
      if (visit[num[i]] > 1)
	{
	  ans++;
	}
    }
  printf ("%d\n", ans);

  return 0;
}
