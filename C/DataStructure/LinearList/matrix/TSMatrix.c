// -1156203886

#include <stdio.h>
#include "tsmatrix.h"

int main()
{
  TSMatrix m, t;

  CreateSMatrix(&m);
  PrintSMatrix(m);

  FastTransposeSMatrix(m, &t);
  PrintSMatrix(t);

  return 0;
}
