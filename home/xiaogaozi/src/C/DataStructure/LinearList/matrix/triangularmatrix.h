// -1156203886

#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define N 4
#define MAXSIZE N * (N + 1) / 2
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct
{
  ElemType data[MAXSIZE];
  ElemType constant;
  int flag; // flag: 1. lower triangular matrix 2. upper triangular matrix
}TriMatrix;

Status CreateTriMatrix(TriMatrix* M)
{
  int i, j, a = 0, f;
  ElemType e;

  printf("What kind of triangular matrix will be created?\n1. lower triangular matrix\n2. upper triangular matrix\nselect: ");
  scanf("%d", &f);
  if (f == 1)
  {
    M->flag = 1;
    for (i = 1; i != N + 1; ++i)
      for (j = 1; j != i + 1; ++j)
      {
        printf("(%d,%d): ", i, j);
        scanf("%d", &e);
        (M->data)[a++] = e;
      }
  }
  else if (f == 2)
  {
    M->flag = 2;
    for (i = 1; i != N + 1; ++i)
      for (j = i; j != N + 1; ++j)
      {
        printf("(%d,%d): ", i, j);
        scanf("%d", &e);
        (M->data)[a++] = e;
      }
  }
  else
  {
    printf("select error!\n");
    exit(0);
  }

  printf("input the constant: ");
  scanf("%d", &e);
  M->constant = e;

  return OK;
}

int Convert(int i, int j)
{
  if (i >= j)
    return i * (i - 1) / 2 + j - 1;
  if (i <= j)
    return j * (j - 1) / 2 + i - 1;
  return 6121;
}

void PrintTriMatrix(TriMatrix M)
{
  int i, j, k = 0;

  for (i = 1; i != N + 1; ++i)
  {
    for (j = 1; j != N + 1; ++j)
    {
      if (M.flag == 1)
      {
        if (i < j)
          printf("%4d", M.constant);
        else
        {
          k = Convert(i, j);
          printf("%4d", M.data[k]);
        }
      }
      if (M.flag == 2)
      {
        if (i > j)
          printf("%4d", M.constant);
        else
        {
          printf("%4d", M.data[k++]);
        }
      }
    }
    printf("\n");
  }
  printf("\n");
}

Status TransposeTriMatrix(TriMatrix M, TriMatrix* T)
{
  int i, j, k, a = 0;

  if (M.flag == 1)
  {
    T->flag = 2;
    for (i = 1; i != N + 1; ++i)
      for (j = i; j != N + 1; ++j)
      {
        k = Convert(j, i);
        (T->data)[a++] = M.data[k];
      }
  }

  if (M.flag == 2)
  {
    T->flag = 1;
    for (i = 1; i != N + 1; ++i)
      for (j = 1; j != i + 1; ++j)
      {
        k = Convert(j, i);
        (T->data)[a++] = M.data[k];
      }
  }

  T->constant = M.constant;
  return OK;
}

#endif
