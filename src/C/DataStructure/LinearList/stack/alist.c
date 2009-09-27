// -1156203886

#include <stdio.h>

int f(unsigned int m, unsigned int n)
{
  return (m * n == 0) ? m + n + 1 : f(m - 1, f(m, n - 1));
}

int main()
{
  printf("%d\n", f(2, 3));

  return 0;
}
