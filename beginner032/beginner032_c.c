#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  int N, K, *s;
  int ans = 0;
  long long int calc = 1;
  int l, r;
  int i;

  scanf ("%d %d", &N, &K);
  s = malloc (sizeof (int) * N);
  for (i = 0; i < N; i++)
    {
      scanf ("%d", &s[i]);
      if (s[i] == 0)
	calc = 0;
    }
  if (!calc)
    {
      printf ("%d\n", N);
      return 0;
    }

  l = 0;
  r = 0;
  calc = s[0];
  while (1)
    {
      while (calc <= K && r < N)
	{
	  r++;
	  calc *= s[r];
	  //printf("while:r=%d\n", r);
	}
      if (ans < r - l)
	ans = r - l;
      if (r == N)
	break;
      while (calc > K && l < r)
	{
	  calc /= s[l];
	  l++;
	}
      //printf("l=%d\n", l);
      if (calc > K)
	{
	  r++;
	  l++;
	  //printf("less than l:r=%d\n", r);
	}
    }

  printf ("%d\n", ans);

  return 0;
}
