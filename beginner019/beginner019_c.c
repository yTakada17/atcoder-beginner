#include <stdio.h>
#include <stdlib.h>

#define NMAX 100000

int comp (const void *a, const void *b);

int
main (int argc, char **argv)
{
  int n = 0;
  int a[NMAX] = { 0 };
  int work = 0;
  int halfnum[NMAX] = { 0 };
  int i = 0;
  int retkind = 0;

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }

  for (i = 0; i < n; i++)
    {

      work = a[i];
      while (work % 2 == 0)
	{
	  work /= 2;
	}

      halfnum[i] = work;
    }

  qsort (halfnum, n, sizeof (int), comp);

  retkind = 1;
  for (i = 1; i < n; i++)
    {
      if (halfnum[i] != halfnum[i - 1])
	{
	  retkind++;
	}
    }

  printf ("%d\n", retkind);

  return 0;
}

int
comp (const void *a, const void *b)
{
  return *(int *) a - *(int *) b;
}
