#include <stdio.h>

char passwd[9];

void
saiki (int rest, char *pnt)
{
  char c;

  if (rest == 0)
    {
      *pnt = '\0';
      printf ("%s\n", passwd);
    }
  else
    {
      for (c = 'a'; c <= 'c'; c++)
	{
	  *pnt = c;
	  saiki (rest - 1, pnt + 1);
	}
    }
}

int
main (void)
{
  int len;

  if (scanf ("%d", &len) > 0)
    {
      saiki (len, passwd);
    }

  return 0;
}
