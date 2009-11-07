#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct LNode
{
  ElemType data;
  struct LNode* next;
}LNode, *LinkList;

// generate random number between 0 and 99
int Random()
{
  return rand() % 100;
}

// initialize a null linklist
Status InitList_L(LinkList* L)
{
  *L = (LinkList) malloc(sizeof(LNode));
  if (!*L)
    exit(OVERFLOW);
  (*L)->next = NULL;
  return OK;
}

/*
 * Insert a node at number i.
 */
Status ListInsert_L(LinkList L, int i, ElemType e)
{
  LinkList p = L;
  int j = 0;

  while (p && j < i - 1)
  {
    p = p->next;
    ++j;
  }

  if (!p || j > i - 1)
    return ERROR;
  LinkList s = (LinkList) malloc(sizeof(LNode));
  if (!s) exit(OVERFLOW);
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

/*
 * Delete a node at number i.
 */
Status ListDelete_L(LinkList L, int i)
{
  if (!L)
    return ERROR;

  LinkList p = L, q;
  int j = 0;

  while (p->next && j < i - 1)
  {
    p = p->next;
    ++j;
  }

  if (!(p->next) || j > i - 1)
    return ERROR;

  q = p->next;
  p->next = q->next;
  free(q);

  return OK;
}

// create a linklist
Status CreateList_L(LinkList L)
{
  if (!L)
    return ERROR;

  int i = 1;
  ElemType e;
  // char c;
  // while (1)
  // {
  //   printf("input a number: ");
  //   scanf("%d", &e);
  //   getchar();
  //   if (ListInsert_L(L, i, e))
  //     ++i;

  //   printf("continue? [Y/n] ");
  //   scanf("%c", &c);
  //   if (c == 'N' || c == 'n')
  //     break;
  // }

  // debug input data
  while (i != 6)
  {
    e = Random();
    if (ListInsert_L(L, i, e))
      ++i;
  }
  
  return OK;
}

// print every element
Status PrintList_L(LinkList L)
{
  if (!L)
    return ERROR;

  L = L->next;
  while (L)
  {
    printf("%2d ", L->data);
    L = L->next;
  }
  printf("\n");
  return OK;
}

Status PriorElem_L(LinkList L, ElemType cur_e, ElemType* pre_e)
{
  if (!L)
    return ERROR;

  L = L->next;
  if (cur_e == L->data)
    return ERROR;

  LinkList p = L, q = p;
  while (p && p->data != cur_e)
  {
    q = p;
    p = p->next;
  }

  if (!p)
    return ERROR;

  *pre_e = q->data;
  return OK;
}

int ListLength_L(LinkList L)
{
  if (!L)
    return ERROR;

  L = L->next;
  int i = 0;
  while (L)
  {
    ++i;
    L = L->next;
  }

  return i;
}

Status ListEmpty_L(LinkList L)
{
  if (!L)
    return ERROR;

  if (L->next)
    return TRUE;

  return FALSE;
}

/*
 * Get element at number i.
 */
Status GetElem_L(LinkList L, int i, ElemType* e)
{
  if (!L)
    return ERROR;

  LinkList p = L->next;
  int j = 1;
  while (p && j < i)
  {
    p = p->next;
    ++j;
  }

  if (!p || j > i)
    return ERROR;

  *e = p->data;
  return OK;
}

/*
 * sort the linklist to ascending order
 */
// void SortList_L(LinkList L)
// {
//   if (!L)
//     return ERROR;
// }
#endif
