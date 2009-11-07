// -1156203886

#include <stdio.h>
#include "sqlist.h"

void StrInsertSort(SqList* L)
{
  int i, j;

  for (i = 2; i <= L->length; ++i)
    if (L->elem[i] < L->elem[i - 1])
    {
      L->elem[0] = L->elem[i];
      L->elem[i] = L->elem[i - 1];
      for (j = i - 2; L->elem[j] > L->elem[0]; --j)
        L->elem[j + 1] = L->elem[j];
      L->elem[j + 1] = L->elem[0];
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
  StrInsertSort(&L);
  PrintList_Sq(L);
  printf("\n");

  return 0;
}
