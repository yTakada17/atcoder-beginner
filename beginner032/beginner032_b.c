#include<stdio.h>
#include<string.h>

int
main (void)
{

  char str[301];
  int strNum[301];
  int count = 0;
  int i, i_max, j, d;
  int flag;
  int gain = 1;

  scanf ("%s", str);
  scanf ("%d", &d);

  for (i = 0, i_max = strlen (str); i < i_max - d + 1; i++)
    {
      strNum[i] = 0;
      gain = 1;
      for (j = 0; j < d; j++)
	{
	  strNum[i] += (int) str[i + j] * gain;
	  gain *= 27;
	}
    }

  /*
     for(i=0; i<i_max-d+1; i++){
     printf("%d\n",strNum[i]);
     }// */



  for (i = 0; i < i_max - d; i++)
    {
      if (strNum[i] != 0)
	{
	  for (j = i + 1; j < i_max - d + 1; j++)
	    {
	      if (strNum[i] == strNum[j])
		{
		  strNum[j] = 0;
		}
	    }
	}
    }



  for (i = 0; i < i_max - d + 1; i++)
    {
      if (strNum[i] != 0)
	count++;
    }

  printf ("%d\n", count);

  return 0;
}
