#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  char s[100001];
  int i, j, k, len = 0, sum = 0, ans = 0, d[100001] = { 0 };

  scanf ("%s", s);

  for (i = 0; i < 100000; i++)
    {
      if (s[i] == 'M')
	{
	  len += 1;
	}
      else if (s[i] == '+')
	{
	  d[len] += 1;
	}
      else if (s[i] == '-')
	{
	  d[len] -= 1;
	}
      else
	{
	  break;
	}
    }

  int a[len];

  for (i = 0; i < len; i++)
    {
      a[i] = d[i + 1];
    }

  for (i = len - 1; i >= 0; i--)
    {
      sum += a[i];
      a[i] = sum;
    }

  int comp (const void *a, const void *b)
  {
    return *(int *) a - *(int *) b;
  }
  int a_size = sizeof (a) / sizeof (a[0]);

  qsort (a, a_size, sizeof (a[0]), comp);

  for (i = 0; i < len / 2; i++)
    {
      ans -= a[i];
    }
  for (i = len / 2; i < len; i++)
    {
      ans += a[i];
    }

  printf ("%d\n", ans);
  return 0;
}
