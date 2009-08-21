// -1156203886

#include <stdio.h>
#include <stdlib.h>
#include "sqqueue.h"

void Josephus(int i, int n, int m)
{
  SqQueue Q;
  QElemType e, j;

  if (i > n) return;
  InitQueue_Sq(&Q, n);
  for (j = 1; j != n + 1; ++j)
    EnQueue_Sq(&Q, j);
  for (j = 0; j != i - 1; ++j)
  {
    DeQueue_Sq(&Q, &e);
    EnQueue_Sq(&Q, e);
  }

  i = 0;
  printf("Josephus: ");
  while (!QueueEmpty_Sq(Q))
  {
    for (j = 0; j != m - 1; ++j)
    {
      DeQueue_Sq(&Q, &e);
      EnQueue_Sq(&Q, e);
    }
    DeQueue_Sq(&Q, &e);
    printf("%d ", e);
  }
  printf("\n");
}

int main()
{
  Josephus(1, 10, 4);

  return 0;
}
