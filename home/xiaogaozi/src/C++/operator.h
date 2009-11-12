// -1156203886

#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"

using namespace std;

inline Query operator&(const Query& lhs, const Query& rhs)
{
  return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query& lhs, const Query& rhs)
{
  return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query& oper)
{
  return new NotQuery(oper);
}

inline ostream& operator<<(ostream& os, const Query& q)
{
  return q.display(os);
}
#endif
