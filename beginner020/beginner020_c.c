#include<stdio.h>
#include<stdlib.h>

#define INF 10000000000

#define min(a,b) (((a)<(b))?(a):(b))

typedef struct node
{
  long h;
  long w;
  long n;
} Node;

long H, W, T;
long s[11][11];
long dis[101][101];

void
init ()
{
  long i, j;
  for (i = 1; i <= 100; i++)
    {
      for (j = 1; j <= 100; j++)
	{
	  if (i == j)
	    dis[i][j] = 0;
	  else
	    dis[i][j] = INF;
	}
    }
}

long
get_cost (char c, long x)
{
  switch (c)
    {
    case '.':
      return 1;
    case 'S':
      return 1;
    case 'G':
      return 1;
    case '#':
      return x;
    default:
      return INF;
    }
}

int
main ()
{
  long i, j, k;
  long l, r, u, d;
  long now;
  Node start, g;
  long count;
  long step;
  char buf[32];
  long x;
  long pre_x;
  long dif;
  long max = 0;

  scanf ("%ld %ld %ld", &H, &W, &T);

  for (i = 1; i <= H; i++)
    {
      scanf ("%s", buf);
      for (j = 1; j <= W; j++)
	{
	  s[i][j] = buf[j - 1];
	  if (s[i][j] == 'S')
	    {
	      start.h = i;
	      start.w = j;
	      start.n = (i - 1) * W + j;
	    }
	  if (s[i][j] == 'G')
	    {
	      g.h = i;
	      g.w = j;
	      g.n = (i - 1) * W + j;
	    }
	}
    }

  x = T / 2;
  dif = T / 2;
  while (1)
    {
      init ();
      for (i = 1; i <= H; i++)
	{
	  for (j = 1; j <= W; j++)
	    {
	      now = (i - 1) * W + j;
	      l = now - 1;
	      r = now + 1;
	      u = now - W;
	      d = now + W;

	      if (j > 1)
		{
		  dis[l][now] = get_cost (s[i][j], x);
		}
	      if (j < W)
		{
		  dis[r][now] = get_cost (s[i][j], x);
		}
	      if (i > 1)
		{
		  dis[u][now] = get_cost (s[i][j], x);
		}
	      if (i < H)
		{
		  dis[d][now] = get_cost (s[i][j], x);
		}
	    }
	}
      for (k = 1; k <= H * W; k++)
	for (i = 1; i <= H * W; i++)
	  for (j = 1; j <= H * W; j++)
	    dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);

      if (dis[start.n][g.n] <= T)
	{
	  if (max < x)
	    max = x;
	  x += (dif / 2);
	}
      else
	{
	  x -= (dif / 2);
	}
      if (dif <= 0)
	break;
      dif /= 2;
    }

  x = max + 1;
  while (1)
    {
      init ();
      for (i = 1; i <= H; i++)
	{
	  for (j = 1; j <= W; j++)
	    {
	      now = (i - 1) * W + j;
	      l = now - 1;
	      r = now + 1;
	      u = now - W;
	      d = now + W;

	      if (j > 1)
		{
		  dis[l][now] = get_cost (s[i][j], x);
		}
	      if (j < W)
		{
		  dis[r][now] = get_cost (s[i][j], x);
		}
	      if (i > 1)
		{
		  dis[u][now] = get_cost (s[i][j], x);
		}
	      if (i < H)
		{
		  dis[d][now] = get_cost (s[i][j], x);
		}
	    }
	}
      for (k = 1; k <= H * W; k++)
	for (i = 1; i <= H * W; i++)
	  for (j = 1; j <= H * W; j++)
	    dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);

      if (dis[start.n][g.n] <= T)
	{
	  if (max < x)
	    max = x;
	  x++;
	}
      else
	{
	  break;
	}
    }

  printf ("%ld\n", max);

  return 0;
}
