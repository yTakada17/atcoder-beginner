#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define INF 10000000000
#define M 1000000007

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

long
combi (int n, int r)
{
  int numerator[r];
  int denominator[r];
  int k, p;
  int pivot;
  int offset;
  long ret = 1;

  if (n < 0 || r < 0 || r > n)
    return 0;

  if (n - r < r)
    r = n - r;
  if (r == 0)
    return 1;
  if (r == 1)
    return n;



  for (k = 0; k < r; k++)
    {
      numerator[k] = n - r + k + 1;
      denominator[k] = k + 1;
    }

  for (p = 2; p <= r; p++)
    {
      pivot = denominator[p - 1];
      if (pivot > 1)
	{
	  offset = (n - r) % p;
	  for (k = p - 1; k < r; k += p)
	    {
	      numerator[k - offset] /= pivot;
	      denominator[k] /= pivot;
	    }
	}
    }

  for (k = 0; k < r; k++)
    {
      if (numerator[k] > 1)
	ret = (ret * numerator[k]) % M;
    }

  return ret;
}

int
main ()
{
  int i, j;
  int n, k;

  scanf ("%d", &n);
  scanf ("%d", &k);

  printf ("%ld\n", combi (n + k - 1, k));

  return 0;
}
