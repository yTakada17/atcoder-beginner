#include <stdio.h>

#define MOD (long)1000000007

int
main ()
{
  long long int A, B, C, D, M, N, P, R, X, Y;
  unsigned long long int E;

  scanf ("%lld%lld%lld", &A, &B, &C);

  // X = (BC-CA)/(AB-BC+CA), Y = (BC-AB)/(AB-BC+CA)
  // step1. calculate the 10^9+5-th power of D := AB-BC+CA ( =: R)
  P = A * ((B + C) % MOD) % MOD;
  if (P < 0)
    P += MOD;
  D = (P - B * C % MOD) % MOD;
  if (D < 0)
    D += MOD;
  R = 1;
  P = D;
  E = MOD - 2;
  while (E)
    {
      if (E & 1)
	{
	  R = R * P % MOD;
	}
      E >>= 1;
      P = P * P % MOD;
    }
  if (R < 0)
    R += MOD;

  // step2. R equals 1/D mod 10^9+7 by Fermat's little theorem
  // step3. calculate X, Y; these are unique because they are over 0 and below 10^9
  M = C * ((MOD + B - A) % MOD) % MOD;
  N = B * ((MOD + C - A) % MOD) % MOD;
  X = M * R % MOD;
  Y = N * R % MOD;

  printf ("%lld %lld\n", X, Y);
  return 0;
}
