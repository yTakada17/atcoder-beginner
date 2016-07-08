#include <stdio.h>
#include <string.h>
int
main ()
{
  char s[51];
  int f = 1, i, len;
  scanf ("%s", s);
  len = strlen (s);
  for (i = 0; i < len && f; i++)
    {
      f = 0;
      if (i < len - 1 && s[i] == 'c' && s[i + 1] == 'h')
	{
	  f = 1;
	  ++i;
	}
      if (s[i] == 'o' || s[i] == 'k' || s[i] == 'u')
	f = 1;
    }
  f ? printf ("YES\n") : printf ("NO\n");
  return 0;
}
