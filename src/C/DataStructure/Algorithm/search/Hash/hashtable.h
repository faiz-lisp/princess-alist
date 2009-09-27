// -1156203886

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>

#define LISTINITSIZE 16
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LEN 13

typedef int Status;
typedef int KeyType;
typedef struct
{
  KeyType key;
  int flag;
}ElemType;
typedef struct
{
  ElemType* elem;
  int count;
  int sizeindex;
}HashTable;

int Hash(KeyType key)
{
  return key % LEN;
}

int Collision(int a, int size, int amount)
{
  return (a + amount) % size;
}

Status InitHash(HashTable* H)
{
  H->elem = (ElemType*) malloc(LISTINITSIZE * sizeof(ElemType));
  if (!H->elem)
    exit(OVERFLOW);
  int i;
  for (i = 0; i != LISTINITSIZE; ++i)
  {
    H->elem[i].key = 0;
    H->elem[i].flag = 0;
  }
  H->count = 0;
  H->sizeindex = LISTINITSIZE;
  return OK;
}

Status CreateHash(HashTable* H, KeyType key)
{
  ElemType* newbase;
  if (H->count >= H->sizeindex)
  {
    newbase = (ElemType*) realloc(H->elem, (H->sizeindex + LISTINCREMENT) * sizeof(ElemType));
    if (!newbase)
      exit(OVERFLOW);
    H->elem = newbase;
    H->sizeindex += LISTINCREMENT;
    int i;
    for (i = 0; i != H->sizeindex; ++i)
      if (!H->elem[i].flag)
        H->elem[i].key = 0;
  }

  int a = Hash(key), amount = 0, b;
  if (a < H->sizeindex && !H->elem[a].key)
  {
    H->elem[a].key = key;
    H->elem[a].flag = 1;
  }
  else
  {
    do
    {
      ++amount;
      b = Collision(a, H->sizeindex, amount);
    }
    while (b < H->sizeindex && H->elem[b].key);
    if (b < H->sizeindex)
    {
      H->elem[b].key = key;
      H->elem[b].flag = 1;
    }
    else
      return ERROR;
  }
  ++H->count;

  return OK;
}

int SearchHash(HashTable H, KeyType key)
{
  int a = Hash(key), amount = 0, b;

  if (a >= H.sizeindex || !H.elem[a].key)
    return ERROR;

  if (H.elem[a].key == key)
    return a + 1;
  else
  {
    do
    {
      ++amount;
      b = Collision(a, H.sizeindex, amount);
    }
    while (b < H.sizeindex && (H.elem[b].key != key) && H.elem[b].key);
    if (H.elem[b].key == key)
      return b + 1;
    else
      return ERROR;
  }
}

#endif
