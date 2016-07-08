#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUF_SIZE 12
int
main ()
{

  char str[12][BUF_SIZE] = { };
  int i = 0, j = 0;
  int count = 0;

  for (i = 0; i < 12; i++)
    {
      scanf ("%s", str[i]);
    }

  for (i = 0; i < 12; i++)
    {
      while (str[i][j] != '\0')
	{
	  if (str[i][j] == 'r')
	    {
	      count++;
	      break;
	    }
	  j++;
	}
      j = 0;
    }

  printf ("%d\n", count);
  return 0;
}
