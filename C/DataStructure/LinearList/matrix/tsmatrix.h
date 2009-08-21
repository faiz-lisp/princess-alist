// -1156203886

#ifndef TSMATRIX_H
#define TSMATRIX_H

#include <stdio.h>

#define MAXSIZE 12500
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;
typedef struct
{
  int i, j;
  ElemType e;
}Triple;
typedef struct
{
  Triple data[MAXSIZE];
  int mu, nu, tu;
}TSMatrix;

Status CreateSMatrix(TSMatrix* M)
{
  int i, j, a = 0;
  ElemType e;

  printf("input the row and column of the matrix: ");
  scanf("%d,%d", &(M->mu), &(M->nu));
  printf("input element, format like this: row,column,element\n");
  do
  {
    printf("%d: ", ++a);
    scanf("%d,%d,%d", &i, &j, &e);
    if (!i || !j || !e)
      break;
    (M->data)[a - 1].i = i;
    (M->data)[a - 1].j = j;
    (M->data)[a - 1].e = e;
  }
  while (1);

  M->tu = a - 1;
  return OK;
}

Status IsZero(TSMatrix M, int i, int j, ElemType* e)
{
  int a;

  for (a = 0; a != M.tu; ++a)
    if (M.data[a].i == i && M.data[a].j == j)
    {
      *e = M.data[a].e;
      return FALSE;
    }
  *e = 0;
  return TRUE;
}

void PrintSMatrix(TSMatrix M)
{
  int i, j;
  ElemType e;

  for (i = 1; i != M.mu + 1; ++i)
  {
    for (j = 1; j != M.nu + 1; ++j)
    {
      IsZero(M, i, j, &e);
      printf("%4d", e);
    }
    printf("\n");
  }
  printf("\n");
}

Status FastTransposeSMatrix(TSMatrix M, TSMatrix* T)
{
  T->mu = M.nu, T->nu = M.mu, T->tu = M.tu;

  int col, num[100], t, cpot[100], p, q;
  if (T->tu)
  {
    for (col = 0; col != M.nu; ++col)
      num[col] = 0;
    for (t = 0; t != M.tu; ++t)
      ++num[M.data[t].j - 1];
    cpot[0] = 1;
    for (col = 1; col != M.nu; ++col)
      cpot[col] = cpot[col - 1] + num[col - 1];
    for (p = 0; p != M.tu; ++p)
    {
      col = M.data[p].j - 1;
      q = cpot[col];
      (T->data)[q - 1].i = M.data[p].j;
      (T->data)[q - 1].j = M.data[p].i;
      (T->data)[q - 1].e = M.data[p].e;
      ++cpot[col];
    }
  }
  return OK;
}

#endif
