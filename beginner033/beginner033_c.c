#include<stdio.h>
#include<string.h>

int
main (void)
{
  int i, len, count = 0, zeroflg = 1;
  char S[100000];

  scanf ("%s", S);
  len = strlen (S);

  for (i = 0; i < len; i++)
    {
      if (S[i] == '0')
	zeroflg = 0;
      if (S[i] == '+')
	{
	  count += zeroflg;
	  zeroflg = 1;
	}
    }
  count += zeroflg;

  printf ("%d\n", count);
  return 0;
}
