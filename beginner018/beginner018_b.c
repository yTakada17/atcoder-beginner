#include <stdio.h>

char S[102];
int N;
int
main (void)
{
  int l, r, i;
  scanf ("%s", S + 1);
  scanf ("%d", &N);
  for (i = 1; i <= N; i++)
    {
      scanf ("%d%d", &l, &r);
      while (l < r)
	{
	  char t = S[l];
	  S[l] = S[r];
	  S[r] = t;
	  l++, r--;
	}
    }
  printf ("%s\n", S + 1);
  return 0;
}
