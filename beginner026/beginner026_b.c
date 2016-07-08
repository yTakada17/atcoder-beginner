#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))


int
BubSort (int x[], int n)
{
  int i, j, temp;

  for (i = 0; i < n - 1; i++)
    {
      for (j = n - 1; j > i; j--)
	{
	  if (x[j - 1] > x[j])
	    {
	      temp = x[j];
	      x[j] = x[j - 1];
	      x[j - 1] = temp;
	    }
	}
    }
  return *x;
}

int
main ()
{

  int circleNum, i;
  scanf ("%d", &circleNum);
  int radius[circleNum];
  for (i = 0; i < circleNum; i++)
    {
      scanf ("%d", &radius[i]);
    }

  BubSort (radius, circleNum);
  double answer = 0.000000000000;
  for (i = 0; i < circleNum; i++)
    {

      if (i % 2 == 1)
	{
	  answer += -(radius[i] * radius[i] * M_PI);
	}
      else
	{
	  answer += radius[i] * radius[i] * M_PI;
	}
    }
  if (answer < 0)
    answer *= -1;
  printf ("%.12f\n", answer);


  return 0;
}
