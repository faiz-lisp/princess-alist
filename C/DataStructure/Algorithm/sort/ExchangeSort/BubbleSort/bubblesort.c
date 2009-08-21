// -1156203886

#include <stdio.h>
#include "sqlist.h"

void BubbleSort(SqList* L)
{
  int i, j;
  ElemType t;

  for (i = 0; i != L->length - 1; ++i)
    for (j = 0; j != L->length - i - 1; ++j)
      if (L->elem[j] > L->elem[j + 1])
      {
        t = L->elem[j];
        L->elem[j] = L->elem[j + 1];
        L->elem[j + 1] = t;
      }
}

int main()
{
  SqList L;
  int i, e;

  freopen("input", "r", stdin);
  
  InitList_Sq(&L);

  for (i = 1; i != 10; ++i)
  {
    scanf("%d", &e);
    ListInsert_Sq(&L, i, e);
  }

  printf("before sort: ");
  PrintList_Sq(L);
  printf("\n");

  printf("after sort: ");
  BubbleSort(&L);
  PrintList_Sq(L);
  printf("\n");

  return 0;
}
