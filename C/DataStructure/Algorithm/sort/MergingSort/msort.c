// -1156203886

#include <stdio.h>
#include "sqlist.h"

void Merge(ElemType* SR, ElemType** TR, int i, int m, int n)
{
  int j, k;
  for (j = m + 1, k = i; i <= m && j <= n; ++k)
  {
    if (SR[i] < SR[j])
      (*TR)[k] = SR[i++];
    else
      (*TR)[k] = SR[j++];
  }
  if (i <= m)
    while (i <= m)
      (*TR)[k++] = SR[i++];
  if (j <= n)
    while (j <= n)
      (*TR)[k++] = SR[j++];
}

void MSort(ElemType* SR, ElemType** TR1, int s, int t)
{
  int m;
  ElemType* TR2 = (ElemType*) malloc((t + 1) * sizeof(ElemType));

  if (s == t)
    (*TR1)[s] = SR[s];
  else
  {
    m = (s + t) / 2;
    MSort(SR, &TR2, s, m);
    MSort(SR, &TR2, m + 1, t);
    Merge(TR2, TR1, s, m, t);
  }
  free(TR2);
}

void MergeSort(SqList* L)
{
  MSort(L->elem, &(L->elem), 1, L->length);
}

/*
 * unrecursion algorithm
 */
// void MergeSort(SqList* L)
// {
//   int i, m, h = 1, len = L->length;
//   ElemType* B = (ElemType*) malloc((len + 1) * sizeof(ElemType));
//   while (h < len)
//   {
//     i = 1;
//     while ((i + h) <= len)
//     {
//       if ((i + 2 * h - 1) <= len)
//         m = i + 2 * h - 1;
//       else
//         m = len;
//       Merge(L->elem, &B, i, i + h - 1, m);
//       i += 2 * h;
//     }
//     for (i = 1; i <= m; ++i)
//       L->elem[i] = B[i];
//     h *= 2;
//   }
//   free(B);
// }

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
  MergeSort(&L);
  PrintList_Sq(L);
  printf("\n");

  return 0;
}
