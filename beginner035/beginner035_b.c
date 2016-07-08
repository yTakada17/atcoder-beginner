#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int
main ()
{
  int x = 0, y = 0;
  char s[100000 + 1] = { };
  int t = 0;
  int i = 0;
  int count = 0;
  scanf ("%s", s);
  scanf ("%d", &t);

  for (i = 0; i < strlen (s); i++)
    {
      if (s[i] == 'L')
	{
	  x--;
	}
      else if (s[i] == 'R')
	{
	  x++;
	}
      else if (s[i] == 'U')
	{
	  y++;
	}
      else if (s[i] == 'D')
	{
	  y--;
	}
      else
	{
	  count++;
	}
    }
  printf ("%d\n", abs (x) + abs (y) + ((t == 1) ? count : -1 * count));
  return 0;
}
