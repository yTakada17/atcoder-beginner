#include<stdio.h>
#define SIZE 4

int
main ()
{

  char str[SIZE][SIZE] = { };
  char ans[SIZE][SIZE] = { };
  int i = 0, j = 0;
  for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
	{
	  scanf (" %c", &str[i][j]);
	}
    }

  for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
	{
	  ans[SIZE - i - 1][SIZE - j - 1] = str[i][j];
	}
    }

  for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE - 1; j++)
	{
	  printf ("%c ", ans[i][j]);
	}
      printf ("%c\n", ans[i][j]);
    }

  return 0;
}
