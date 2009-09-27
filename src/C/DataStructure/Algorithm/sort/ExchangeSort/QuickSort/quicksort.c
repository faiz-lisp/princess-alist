// -1156203886

#include <stdio.h>
#include "sqlist.h"

int Partition(SqList* L, int low, int high)
{
  L->elem[0] = L->elem[low];
  int pivotkey = L->elem[low];
  while (low < high)
  {
    while (low < high && L->elem[high] >= pivotkey)
      --high;
    L->elem[low] = L->elem[high];
    while (low < high && L->elem[low] <= pivotkey)
      ++low;
    L->elem[high] = L->elem[low];
  }
  L->elem[low] = L->elem[0];
  return low;
}

void QuickSort(SqList* L, int low, int high)
{
  int pivotkey;
  if (low < high)
  {
    pivotkey = Partition(L, low, high);
    QuickSort(L, low, pivotkey - 1);
    QuickSort(L, pivotkey + 1, high);
  }
}

int main()
{
  SqList L;
  int i, e;

  freopen("input", "r", stdin);

  InitList_Sq(&L);

  for (i = 1; i != 9; ++i)
  {
    scanf("%d", &e);
    ListInsert_Sq(&L, i, e);
  }

  printf("before sort: ");
  PrintList_Sq(L);
  printf("\n");

  printf("after sort: ");
  QuickSort(&L, 1, L.length);
  PrintList_Sq(L);
  printf("\n");

  return 0;
}
