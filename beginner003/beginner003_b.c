#include<stdio.h>
#include<string.h>
#define BUF_SIZE 11

int
main ()
{

  char s[BUF_SIZE] = { }, t[BUF_SIZE] =
  {
  };
  int i = 0;

  scanf ("%s", s);
  scanf ("%s", t);

  while (s[i] != '\0')
    {
      if (s[i] == '@' && t[i] != '@')
	{
	  if (t[i] == 'a' || t[i] == 't' || t[i] == 'c' || t[i] == 'o'
	      || t[i] == 'd' || t[i] == 'e' || t[i] == 'r')
	    {
	      s[i] = t[i];
	    }
	}
      else if (s[i] != '@' && t[i] == '@')
	{
	  if (s[i] == 'a' || s[i] == 't' || s[i] == 'c' || s[i] == 'o'
	      || s[i] == 'd' || s[i] == 'e' || s[i] == 'r')
	    {
	      t[i] = s[i];
	    }
	}
      i++;

    }


  if (strcmp (s, t) == 0)
    {
      printf ("You can win\n");
    }
  else
    {
      printf ("You will lose\n");
    }

  return 0;
}
