// -1156203886

#include <stdio.h>
#include "linkqueue.h"
#include "linklist.h"

typedef struct
{
  int OccurTime;
  int NType;
}Event, ElemType;
typedef LinkList EventList;
typedef struct
{
  int ArrivalTime;
  int Duration;
}QElemType;

EventList ev;
Event en;
LinkQueue q[5];
QElemType customer;
int TotalTime, CustomerNum;

int cmp(Event a, Event b)
{
}

void OrderInsert(EventList ev, Event en, int (*cmp)(Event, Event))
{
}

void OpenForDay()
{
  TotalTime = 0;
  CustomerNum = 0;
  InitList_L(&ev);
  en.OccurTime = 0;
  en.NType = 0;
  OrderInsert(ev, en, cmp);
}

void Bank_Simulation(int CloseTime)
{
  OpenForDay();
}

int main()
{

  return 0;
}
