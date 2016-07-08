#include<stdio.h>
#include<string.h>
#define SIZE 1000
#define BUF_SIZE 20

int
main ()
{
  int n = 0;
  int i = 0;
  int sum = 0;
  char str[SIZE][BUF_SIZE] = { };
  int ary[SIZE] = { };
  char ans[BUF_SIZE] = { };
  int max = 0;

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%s %d", str[i], &ary[i]);
      sum += ary[i];
      if (max < ary[i])
	{
	  max = ary[i];
	  strcpy (ans, str[i]);
	}
    }

  if (sum / 2 < max)
    {
      printf ("%s\n", ans);
    }
  else
    {
      printf ("atcoder\n");
    }


  return 0;
}
