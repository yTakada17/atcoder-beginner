#include <stdio.h>
#include <memory.h>

#define K_MAX           100
#define SWAP(a, b, c)   c = a; a = b; b = c;
int
main ()
{

  unsigned int m;
  unsigned int *pa1, *pa2, *pa3;
  unsigned int a1[K_MAX];
  unsigned int a2[K_MAX];
  unsigned int (*pmx1)[K_MAX], (*pmx2)[K_MAX], (*pmx3)[K_MAX];
  unsigned int mx1[K_MAX][K_MAX];
  unsigned int mx2[K_MAX][K_MAX];
  int i, j, k, l;

  memset (a1, 0, sizeof (a1));
  memset (a2, 0, sizeof (a2));
  memset (mx1, 0, sizeof (mx1));
  memset (mx2, 0, sizeof (mx2));

  pa1 = a1;
  pa2 = a2;
  pmx1 = mx1;
  pmx2 = mx2;

  scanf ("%d %d", &k, &m);
  for (i = 0; i < k; i++)
    {
      scanf ("%d", pa1 + k - i - 1);
    }
  for (i = 0; i < k; i++)
    {
      scanf ("%d", pmx1[0] + i);
    }
  for (i = 1; i < k; i++)
    {
      pmx1[i][i - 1] = -1;
    }

  if (m <= k)
    {
      printf ("%u\n", pa1[k - m]);
      return 0;
    }

  for (m -= k; m > 0; m >>= 1)
    {
      if (m & 1)
	{
	  // a <- mx * a
	  memset (pa2, 0, sizeof (a1));
	  for (i = 0; i < k; i++)
	    for (j = 0; j < k; j++)
	      pa2[i] ^= pmx1[i][j] & pa1[j];
	  SWAP (pa1, pa2, pa3);
	}
      // mx <- mx x mx
      memset (pmx2, 0, sizeof (mx1));
      for (i = 0; i < k; i++)
	for (j = 0; j < k; j++)
	  for (l = 0; l < k; l++)
	    pmx2[i][j] ^= pmx1[i][l] & pmx1[l][j];
      SWAP (pmx1, pmx2, pmx3);
    }

  printf ("%u\n", pa1[0]);

  return 0;
}
