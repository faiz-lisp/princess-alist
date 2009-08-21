// -1156203886

#include <stdio.h>
#include "sqlist.h"

typedef SqList HeapType;

void HeapAdjust(HeapType* H, int s, int m)
{
  int rc = H->elem[s], i;
  for (i = 2 * s; i <= m; i *= 2)
  {
    if (i < m && (H->elem[i] < H->elem[i + 1]))
      ++i;
    if (rc >= H->elem[i])
      break;
    H->elem[s] = H->elem[i];
    s = i;
  }
  H->elem[s] = rc;
}

void HeapSort(HeapType* H)
{
  int i, t;
  for (i = H->length / 2; i > 0; --i)
    HeapAdjust(H, i, H->length);
  for (i = H->length; i > 1; --i)
  {
    t = H->elem[1];
    H->elem[1] = H->elem[i];
    H->elem[i] = t;
    HeapAdjust(H, 1, i - 1);
  }
}

int main()
{
  HeapType H;
  int i, e;

  freopen("input", "r", stdin);

  InitList_Sq(&H);

  for (i = 1; i != 9; ++i)
  {
    scanf("%d", &e);
    ListInsert_Sq(&H, i, e);
  }

  printf("before sort: ");
  PrintList_Sq(H);
  printf("\n");

  printf("after sort: ");
  HeapSort(&H);
  PrintList_Sq(H);
  printf("\n");

  return 0;
}
