#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
main ()
{
  int count = 0, i, n;
  char *s = malloc (1001);
  scanf ("%1000s", s);
  n = strlen (s);
  for (i = 1; i < n; i++)
    {
      if (s[i] == s[i - 1])
	{
	  count++;
	}
      else
	{
	  printf ("%c%d", s[i - 1], count + 1);
	  count = 0;
	}
    }
  printf ("%c%d", s[i - 1], count + 1);
  putchar ('\n');
  return 0;
}
