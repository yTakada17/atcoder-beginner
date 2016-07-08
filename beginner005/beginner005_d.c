#include <stdio.h>

#define NMAX 50
#define QMAX 2500

int getscore (int x, int y, int w, int h);
int getmaxscore (int count);

int n = 0;
int d[NMAX][NMAX] = { {0} };
int cntscore[QMAX] = { 0 };

int
main (int argc, char **argv)
{
  int q = 0;
  int p[QMAX] = { 0 };
  int i = 0;
  int j = 0;

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  scanf ("%d", &d[i][j]);
	}
    }
  scanf ("%d", &q);
  for (i = 0; i < q; i++)
    {
      scanf ("%d", &p[i]);
    }

  for (i = 0; i < q; i++)
    {
      printf ("%d\n", getmaxscore (p[i]));
    }

  return 0;
}

int
getscore (int x, int y, int w, int h)
{
  int i = 0;
  int j = 0;
  int score = 0;

  for (i = y; i < y + h; i++)
    {
      for (j = x; j < x + w; j++)
	{
	  score += d[i][j];
	}
    }

  return score;
}

int
getmaxscore (int count)
{
  int i = 0;
  int w = 0;
  int h = 0;
  int x = 0;
  int y = 0;
  int max = 0;
  int score = 0;

  if (cntscore[count - 1] > 0)
    {
      return cntscore[count - 1];
    }

  for (i = 1; i < count; i++)
    {
      score = getmaxscore (i);
      if (max < score)
	{
	  max = score;
	}
    }

  for (w = 1; w <= n && w <= count; w++)
    {

      if (count % w > 0)
	{
	  continue;
	}

      h = count / w;

      for (y = 0; y + h <= n; y++)
	{
	  for (x = 0; x + w <= n; x++)
	    {
	      score = getscore (x, y, w, h);
	      if (max < score)
		{
		  max = score;
		}
	    }
	}
    }

  cntscore[count - 1] = max;

  return cntscore[count - 1];
}
