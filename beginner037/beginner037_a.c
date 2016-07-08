#include<stdio.h>

int
main ()
{
  int a, b, c;
  int count = 0;
  scanf ("%d %d %d", &a, &b, &c);
  if (a < b)
    {
      count = c / a;
      c -= count * a;
      while (1)
	{
	  c -= b;
	  if (c > 0)
	    {
	      count++;
	    }
	  else
	    {
	      break;
	    }
	}
    }
  else
    {
      count = c / b;
      c -= count * b;
      while (1)
	{
	  c -= b;
	  if (c > 0)
	    {
	      count++;
	    }
	  else
	    {
	      break;
	    }
	}
    }
  printf ("%d\n", count);
  return 0;
}
