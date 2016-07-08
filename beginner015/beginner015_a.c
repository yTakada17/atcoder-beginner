#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 55
int
main ()
{

  char a[BUF_SIZE] = { };
  char b[BUF_SIZE] = { };

  scanf ("%s", a);
  scanf ("%s", b);

  if (strlen (a) > strlen (b))
    {
      printf ("%s\n", a);
    }
  else
    {
      printf ("%s\n", b);
    }
  return 0;
}
