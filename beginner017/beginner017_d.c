#include<stdio.h>
#define MOD 1000000007
int
main ()
{

  int N, M, i, j, tail = 0;
  scanf ("%d %d", &N, &M);
  int supSt[N + 1];
  int supMap[M + 1];
  long long int dp[N + 1], num = 2;
  supSt[0] = -1;

  for (i = 1; i < N + 1; i++)
    {
      scanf ("%d", &supSt[i]);
    }
  for (i = 0; i <= M; i++)
    supMap[i] = 0;
  supMap[supSt[1]] = 1;
  dp[0] = 1;
  dp[1] = 1;
  for (i = 2; i < N + 1; i++)
    {
      if (supMap[supSt[i]] == 0)
	{
	  dp[i] = dp[i - 1] * 2;
	  supMap[supSt[i]] = 1;
	}
      else
	{
	  for (j = tail; supSt[i] != supSt[j]; j++)
	    {
	      supMap[supSt[j]] = 0;
	      num -= dp[j];
	    }
	  dp[i] = num;
	  num -= dp[j];
	  tail = j + 1;
	}
      num += dp[i];
      dp[i] = (dp[i] + MOD) % MOD;
      num = (num + MOD) % MOD;
    }
  printf ("%lld\n", (dp[N] + MOD) % MOD);
  return 0;
}
