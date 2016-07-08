#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 101
#define DUMMY '_'

void sort (char *str, const char *org, char *sorted, int k);
int check (const char *str, const char *org);
int cmpc (const void *a, const void *b);

int
main (int argc, char **argv)
{
  int n = 0;
  int k = 0;
  char s[MAX_LEN] = "";
  char t[MAX_LEN] = "";
  char sorted[MAX_LEN] = "";

  scanf ("%d %d", &n, &k);
  scanf ("%s", s);
  strcpy (sorted, s);
  qsort (sorted, n, sizeof (char), cmpc);
  sort (t, s, sorted, k);
  printf ("%s\n", t);

  return 0;
}

void
sort (char *str, const char *org, char *sorted, int k)
{
  int i = 0;
  char buf = '\0';

  if (org[0] == '\0')
    {
      return;
    }

  for (i = 0; sorted[i] != '\0'; i++)
    {

      if (sorted[i] == DUMMY)
	{
	  continue;
	}

      if (org[0] == sorted[i])
	{
	  *str = sorted[i];
	  sorted[i] = DUMMY;
	  break;
	}
      else
	{
	  buf = sorted[i];
	  sorted[i] = DUMMY;
	  if (k > check (sorted, &org[1]))
	    {
	      k--;
	      *str = buf;
	      break;
	    }
	  else
	    {
	      sorted[i] = buf;
	    }
	}
    }

  sort (&str[1], &org[1], sorted, k);

}

int
check (const char *str, const char *org)
{
  int i = 0;
  int j = 0;
  int samecount = 0;
  int sameflag[MAX_LEN];

  memset (sameflag, 0x00, sizeof (sameflag));

  while (org[i] != '\0')
    {
      j = 0;
      while (str[j] != '\0')
	{
	  if (sameflag[j] == 0 && org[i] == str[j])
	    {
	      samecount++;
	      sameflag[j] = 1;
	      break;
	    }
	  j++;
	}
      i++;
    }

  return i - samecount;
}

int
cmpc (const void *a, const void *b)
{
  const char *chara = (const char *) a;
  const char *charb = (const char *) b;

  if (*chara < *charb)
    {
      return -1;
    }
  else if (*chara > *charb)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
