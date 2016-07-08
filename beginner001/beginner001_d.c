#include <stdio.h>

int
main (void)
{
  int n = 0, time_o[2] = { };
  int table[289] = { };
  int s[30000] = { };
  int e[30000] = { };
  int i, j;

  scanf ("%d", &n);

  for (i = 0; i < n; i++)
    {
      scanf ("%d-%d", &s[i], &e[i]);
    }

  for (i = 0; i < n; i++)
    {
      if (s[i] % 5)
	{
	  s[i] -= s[i] % 5;
	}
      if (e[i] % 5)
	{
	  e[i] += 5 - e[i] % 5;
	}
      if (e[i] % 100 == 60)
	{
	  e[i] += 40;
	}
    }

  for (i = 0; i < n; i++)
    {
      j = ((s[i] / 100) * 60 + s[i] % 100) / 5;
      (table[j])++;
      j = ((e[i] / 100) * 60 + e[i] % 100) / 5;
      (table[j])--;
    }

  for (i = 1; i < 289; i++)
    {
      table[i] += table[i - 1];
    }

  for (i = 0; i < 289; i++)
    {
      if (table[i] && (!i || !(table[i - 1])))
	{
	  printf ("%04d-", (i / 12) * 100 + i % 12 * 5);
	}
      else if (!(table[i]) && i && table[i - 1])
	{
	  printf ("%04d\n", (i / 12) * 100 + i % 12 * 5);
	}
    }

  return 0;
}
