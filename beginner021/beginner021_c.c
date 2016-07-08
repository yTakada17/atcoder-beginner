#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int
main ()
{
  int N, a, b, M, i, x, y, qp, np, qp2, flag;
  int data[100][100], cnt[100], visit[100], queue[100], queue2[100];

  scanf ("%d %d %d %d", &N, &a, &b, &M);

  memset (data, 0, sizeof (data));
  memset (cnt, 0, sizeof (cnt));
  memset (visit, 0, sizeof (visit));

  qp = 0;
  flag = 0;
  for (i = 0; i < M; i++)
    {
      scanf ("%d %d", &x, &y);
      if (x == a)
	{
	  queue[qp++] = y - 1;
	  cnt[y - 1] = 1;
	  visit[y - 1] = 1;
	  if (y == b)
	    flag = 1;
	}
      else if (y == a)
	{
	  queue[qp++] = x - 1;
	  cnt[x - 1] = 1;
	  visit[x - 1] = 1;
	  if (x == b)
	    flag = 1;
	}
      else
	{
	  data[x - 1][y - 1] = 1;
	  data[y - 1][x - 1] = 1;
	}
    }
  cnt[a - 1] = 1;
  visit[a - 1] = 1;

  while (!flag)
    {
      qp2 = 0;
      for (np = 0; np < qp; np++)
	{
	  for (i = 0; i < N; i++)
	    {
	      if (visit[i] != visit[queue[np]] && data[queue[np]][i])
		{
		  cnt[i] += cnt[queue[np]];
		  cnt[i] %= MOD;
		  data[queue[np]][i] = 0;
		  data[i][queue[np]] = 0;
		  queue2[qp2++] = i;
		  visit[i] = visit[queue[np]] + 1;
		  if (i == b - 1)
		    flag = 1;
		}
	    }
	}
      if (!qp2 || flag)
	break;
      memcpy (queue, queue2, sizeof (queue));
      qp = qp2;
    }

  printf ("%d\n", cnt[b - 1] % MOD);

  return 0;
}
