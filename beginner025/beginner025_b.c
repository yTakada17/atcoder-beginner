#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
int
main ()
{
  int n = 0, a = 0, b = 0;
  int d[SIZE] = { };
  char s[SIZE][SIZE] = { };
  int i = 0;
  char state[] = "East";
  int now = 0;

  scanf ("%d %d %d", &n, &a, &b);
  for (i = 0; i < n; i++)
    {
      scanf ("%s %d", s[i], &d[i]);
    }

  for (i = 0; i < n; i++)
    {
      if (d[i] < a)
	{
	  if (strcmp (s[i], "East") == 0)
	    {
	      now += a;
	    }
	  else if (strcmp (s[i], "West") == 0)
	    {
	      now -= a;
	    }
	}
      else if (a <= d[i] && d[i] <= b)
	{
	  if (strcmp (s[i], "East") == 0)
	    {
	      now += d[i];
	    }
	  else if (strcmp (s[i], "West") == 0)
	    {
	      now -= d[i];
	    }
	}
      else if (b < d[i])
	{
	  if (strcmp (s[i], "East") == 0)
	    {
	      now += b;
	    }
	  else if (strcmp (s[i], "West") == 0)
	    {
	      now -= b;
	    }
	}
    }

  if (now == 0)
    {
      printf ("0\n");
    }
  else
    {
      if (now > 0)
	{
	  strcpy (state, "East");
	}
      else if (now < 0)
	{
	  strcpy (state, "West");
	  now = abs (now);
	}
      printf ("%s %d\n", state, now);
    }
  return 0;
}
