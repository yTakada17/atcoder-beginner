#include<stdio.h>
int
main ()
{
  long long int n, x = 1, N;
  int depth = 0;
  scanf ("%ld", &N);

  for (n = N; n > 0; n /= 2)
    depth++;

  if (depth % 2 == 0)
    {
      while (1)
	{
	  x = 2 * x;
	  //printf("%ld\n",x);
	  if (x > N)
	    {
	      printf ("Aoki\n");
	      return 0;
	    }
	  x = 2 * x + 1;
	  //printf("%ld\n",x);
	  if (x > N)
	    {
	      printf ("Takahashi\n");
	      return 0;
	    }
	}
    }
  else
    {
      while (1)
	{
	  x = 2 * x + 1;
	  //printf("%ld\n",x);
	  if (x > N)
	    {
	      printf ("Aoki\n");
	      return 0;
	    }
	  x = 2 * x;
	  //printf("%ld\n",x);
	  if (x > N)
	    {
	      printf ("Takahashi\n");
	      return 0;
	    }
	}
    }
  return 0;
}
