#include <stdio.h>
#include <stdlib.h>

int n;
long long h[100000], s[100000], d[100000], b[100000];

void
mergeSort (long long *a)
{
  void merge (int head, int last)
  {
    int mid, i, j, k;

    if (head < last)
      {
	mid = (head + last) / 2;

	merge (head, mid);
	merge (mid + 1, last);

	for (i = head; i <= mid; i++)
	  {
	    b[i] = a[i];
	  }
	for (i = mid + 1; i <= last; i++)
	  {
	    b[i] = a[last + mid + 1 - i];
	  }

	j = head;
	k = last;

	for (i = head; i <= last; i++)
	  {
	    if (b[j] <= b[k])
	      {
		a[i] = b[j++];
	      }
	    else
	      {
		a[i] = b[k--];
	      }
	  }
      }
  }
  merge (0, n - 1);
}

int
solve (long long x)
{
  int i;

  for (i = 0; i < n; i++)
    {
      if (x < h[i])
	{
	  return 0;
	}
      else
	{
	  d[i] = (x - h[i]) / s[i];
	}
    }

  mergeSort (d);

  for (i = 0; i < n; i++)
    {
      if (d[i] < (long long) i)
	{
	  return 0;
	}
    }
  return 1;
}

int
main ()
{
  int i;
  long long x, l = 0, r = 1e15;

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%lld %lld", &h[i], &s[i]);
    }

  while (r - l > 1)
    {
      x = (l + r) / 2;
      if (solve (x))
	{
	  r = x;
	}
      else
	{
	  l = x;
	}
    }

  printf ("%lld\n", r);
  return 0;
}
