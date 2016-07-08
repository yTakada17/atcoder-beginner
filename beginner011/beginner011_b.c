#include<stdio.h>
#include<ctype.h>

#define BUF_SIZE 13
int
main ()
{
  char s[BUF_SIZE] = { };
  int i = 0;

  scanf ("%s", s);
  for (i = 0; s[i] != '\0'; i++)
    {
      if (i == 0)
	{
	  s[i] = toupper (s[i]);
	}
      else
	{
	  s[i] = tolower (s[i]);
	}
    }

  printf ("%s\n", s);

  return 0;
}
