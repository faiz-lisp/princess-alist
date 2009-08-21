// -1156203886

#include <stdio.h>
#include "triangularmatrix.h"

int main()
{
  TriMatrix m, t;

  CreateTriMatrix(&m);
  PrintTriMatrix(m);

  TransposeTriMatrix(m, &t);
  PrintTriMatrix(t);

  return 0;
}
