#include<stdio.h>

#define BUF_SIZE 30
int
main ()
{

  char w[BUF_SIZE] = { };
  char ans[BUF_SIZE] = { };
  scanf ("%s", w);
  int i = 0, index = 0;

  while (w[i] != '\0')
    {
      if (w[i] != 'a' && w[i] != 'i' && w[i] != 'u' && w[i] != 'e'
	  && w[i] != 'o')
	{
	  ans[index] = w[i];
	  index++;
	}
      i++;
    }

  printf ("%s\n", ans);
  return 0;
}
