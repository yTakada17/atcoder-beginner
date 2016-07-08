#include <stdio.h>
#include <string.h>

int
main ()
{
  int d, f1, f2, i, j, K, m, N, u;
  unsigned long int p = 0;

  scanf ("%d%d\n", &K, &N);

  int l[K], sl[K], vl[N], wl[N];
  char s[K][4], t[K][4], v[N][10], w[N][27], *x;
  for (i = 0; i < N; i++)
    {
      scanf ("%[0-9] %[a-z]%*c", &v[i], &w[i]);
      vl[i] = strlen (v[i]);
      wl[i] = strlen (w[i]);
    }

  //  printf("Step 1\n");
  for (i = 0; i < K; i++)
    {
      p += 1 << 2 * i;
    }
  while (1)
    {
      f1 = 0;
      f2 = 0;
      //  printf("Step 2.1  ");
      for (i = 0; i < K; i++)
	{
	  sl[i] = (p >> 2 * i) & 3;
	  if (!sl[i])
	    {
	      sl[i]++;
	      p += 1 << 2 * i;
	    }
	  l[i] = 0;
	}
      /*  for (i=K;i>0;i--) {
         printf("%d ", sl[i-1]);
         }
         printf("Step 2.2  "); */
      for (i = 0; i < N; i++)
	{
	  u = 0;
	  m = 0;
	  for (j = 0; j < vl[i]; j++)
	    {
	      d = v[i][j] - '1';
	      //  printf("%d,%d,%d,%d,%d ", i, j, vl[i], d, l[d]);
	      u += sl[d];
	    }
	  if (u != wl[i])
	    f1++;
	}

      //  printf("Step 2.3   ");
      //          if (!memcmp(u, wl, sizeof(int)*N)) f1++;

      for (i = 0; i < N; i++)
	{
	  u = 0;
	  m = 0;
	  x = w[i];
	  for (j = 0; j < vl[i]; j++)
	    {
	      d = v[i][j] - '1';
	      if (!l[d])
		memmove (s[d], x, sizeof (char) * sl[d]);
	      else
		{
		  memmove (t[d], x, sizeof (char) * sl[d]);
		  if (memcmp (t[d], s[d], sizeof (char) * sl[d]))
		    f2++;
		}
	      x += sl[d];
	      l[d]++;
	    }
	}
      //  printf("%d %d \n", f1, f2);
      if (f1 == 0 && f2 == 0)
	break;
      else
	{
	  p++;
	  if (p >= (1 << 2 * K))
	    return 1;
	  else
	    continue;
	}
    }

  //  printf("Step 3\n");
  for (i = 0; i < K; i++)
    {
      for (j = 0; j < sl[i]; j++)
	{
	  printf ("%c", s[i][j]);
	}
      printf ("\n");
    }

  return 0;
}
