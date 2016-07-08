#include<stdio.h>
#include<string.h>

int
main ()
{
  int m = 0, d = 0;
  int i = 0;
  char s[4] = "NO";
  scanf ("%d %d", &m, &d);

  if (m < d)
    {
      printf ("NO\n");
    }
  else
    {
      for (i = 1; d * i <= m; i++)
	{
	  if (d * i == m)
	    {
	      strcpy (s, "YES");
	    }
	}
      printf ("%s\n", s);
    }

  return 0;
}
