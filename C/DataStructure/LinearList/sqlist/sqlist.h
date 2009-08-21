// -1156230886

/*
 * element start at index 1, index 0 unused.
 */

#ifndef SQLIST_H
#define SQLIST_H

#include <stdlib.h>

#define LISTINITSIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Statue;
typedef struct
{
  ElemType* elem;
  int length;
  int listsize;
}SqList;

Statue InitList_Sq(SqList* L)
{
  L->elem = (ElemType*) malloc(LISTINITSIZE * sizeof(ElemType));
  if (!L->elem)
    exit(OVERFLOW);
  L->length = 0;
  L->listsize = LISTINITSIZE;
  return OK;
}

Statue ListInsert_Sq(SqList* L, int i, ElemType e)
{
  if (!L->elem)
    return ERROR;
  if (i < 1 || i > L->length + 1)
    return ERROR;

  ElemType* newbase;
  if (L->length >= L->listsize)
  {
    newbase = (ElemType*) realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
    if (!newbase)
      exit(OVERFLOW);
    L->elem = newbase;
    L->listsize += LISTINCREMENT;
  }

  ElemType* p;
  ElemType* q;
  q = &(L->elem[i]);
  for (p = &(L->elem[L->length]); p >= q; --p)
    *(p + 1) = *p;
  *q = e;
  ++L->length;

  return OK;
}

void PrintList_Sq(SqList L)
{
  int i;

  for (i = 1; i <= L.length; ++i)
    printf("%d ", L.elem[i]);
}

#endif
