#include <stdio.h>
#include <string.h>

int chokudai;
int naoko;
void ev_func ();
int max (int a, int b);
int min (int a, int b);

int dfs (int depth);


int b[2][3];
int c[3][2];
int field[3][3];

int
main ()
{


  memset (field, 0, sizeof (field));

  int i, j;

  int sum = 0;
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  scanf (" %d", &b[i][j]);
	  sum += b[i][j];
	}
    }
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 2; j++)
	{
	  scanf (" %d", &c[i][j]);
	  sum += c[i][j];
	}
    }
  int ans = dfs (0);
  int ans2 = sum - ans;
  printf ("%d\n%d\n", ans, ans2);

  return 0;
}

int
dfs (int depth)
{
  int i, j;

  if (depth == 9)
    {
      int ans = 0;

      for (i = 0; i < 2; i++)
	{
	  for (j = 0; j < 3; j++)
	    {
	      if (field[i][j] == field[i + 1][j])
		{
		  ans += b[i][j];
		}
	    }
	}

      for (i = 0; i < 3; i++)
	{
	  for (j = 0; j < 2; j++)
	    {
	      if (field[i][j] == field[i][j + 1])
		{
		  ans += c[i][j];
		}
	    }
	}
      return ans;
    }

  else if (depth % 2 == 0)
    {
      int ans = 0;
      for (i = 0; i < 3; i++)
	{
	  for (j = 0; j < 3; j++)
	    {
	      if (field[i][j] != 0)
		{
		  continue;
		}

	      field[i][j] = 1;
	      int temp = dfs (depth + 1);
	      ans = max (temp, ans);
	      field[i][j] = 0;
	    }
	}
      return ans;
    }

  else
    {
      int ans = 999999;
      for (i = 0; i < 3; i++)
	{
	  for (j = 0; j < 3; j++)
	    {
	      if (field[i][j] != 0)
		{
		  continue;
		}

	      field[i][j] = 2;
	      int temp = dfs (depth + 1);
	      ans = min (temp, ans);
	      field[i][j] = 0;
	    }
	}
      return ans;
    }
}

int
max (int a, int b)
{
  if (a >= b)
    {
      return a;
    }
  else
    {
      return b;
    }
}

int
min (int a, int b)
{
  if (a >= b)
    {
      return b;
    }
  else
    {
      return a;
    }
}
