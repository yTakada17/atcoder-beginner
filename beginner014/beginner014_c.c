#include<stdio.h>

int
main (void)
{

  int i, n, a, b, con, maxcon;
  int p[1000002] = { 0 };
  con = 0;
  maxcon = 0;

  scanf ("%d", &n);
  while (n--)
    {
      scanf ("%d %d", &a, &b);
      p[a]++;
      p[b + 1]--;
    }

  for (i = 0; i < 1000001; i++)
    {
      con += p[i];
      if (con > maxcon)
	{
	  maxcon = con;;
	}
    }

  printf ("%d\n", maxcon);

  return 0;
}
