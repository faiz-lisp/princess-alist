// -1156203886

#include <stdio.h>
#include "sqlist.h"

int BiSearch(SqList L, ElemType e)
{
  int low = 0, high = L.length - 1, mid;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (e == L.elem[mid])
      return mid + 1;
    else if (e < L.elem[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return 0;
}

int main()
{
  SqList L;
  int i = 1;
  ElemType e;

  freopen("input", "r", stdin);
  freopen("output", "w", stdout);

  InitList_Sq(&L);
  scanf("%d", &e);
  while (e != 65535)
  {
    ListInsert_Sq(&L, i++, e);
    scanf("%d", &e);
  }

  scanf("%d", &e);
  printf("%d\n", BiSearch(L, e));

  return 0;
}
