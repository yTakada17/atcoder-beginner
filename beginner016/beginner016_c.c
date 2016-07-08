#include <stdio.h>


int
main (int argc, char **argv)
{
  int i, j, k;
  int user_num, relation_num;
  int cnt;
  int map[101][101] = { };
  int result_map[101][101] = { };

  scanf ("%d %d", &user_num, &relation_num);

  for (i = 0; i < relation_num; i++)
    {
      scanf ("%d %d", &j, &k);
      map[j][k] = 1;
      map[k][j] = 1;
    }

  for (i = 1; i <= user_num; i++)
    {
      cnt = 0;
      for (j = 1; j <= user_num; j++)
	{
	  if (map[i][j] == 1)
	    {
	      for (k = 1; k <= user_num; k++)
		{
		  if (map[j][k] == 1 && map[i][k] == 0 && i != k)
		    {
		      result_map[i][k] = 1;
		    }
		}
	    }
	}
    }

  for (i = 1; i <= user_num; i++)
    {
      cnt = 0;
      for (j = 1; j <= user_num; j++)
	{
	  if (result_map[i][j] == 1)
	    {
	      cnt++;
	    }
	}
      printf ("%d\n", cnt);
    }
  return 0;
}
