// -1156203886

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef struct QNode
{
  QElemType data;
  struct QNode* next;
}QNode, *QueuePtr;
typedef struct
{
  QueuePtr front;
  QueuePtr rear;
}LinkQueue;

Status InitQueue_L(LinkQueue* Q)
{
  Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
  if (!Q->front) exit(OVERFLOW);
  Q->front->next = NULL;
  return OK;
}

Status DestroyQueue_L(LinkQueue* Q)
{
  while (Q->front)
  {
    Q->rear = Q->front->next;
    free(Q->front);
    Q->front = Q->rear;
  }
  return OK;
}

Status EnQueue_L(LinkQueue* Q, QElemType e)
{
  if (!Q->front) return ERROR;
  QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
  if (!p) exit(OVERFLOW);
  p->data = e;
  p->next = NULL;
  Q->rear->next = p;
  Q->rear = p;
  return OK;
}

Status DeQueue_L(LinkQueue* Q, QElemType* e)
{
  if (!Q->front) return ERROR;
  if (Q->front == Q->rear) return ERROR;
  QueuePtr p = Q->front->next;
  *e = p->data;
  Q->front->next = p->next;
  if (Q->rear == p) Q->rear = Q->front;
  free(p);
  return OK;
}

#endif
