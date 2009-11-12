// -1156203886

#ifndef NOTQUERY_H
#define NOTQUERY_H
#include <iostream>
#include <set>
#include "Query.h"
#include "TextQuery.h"
#include "Query_base.h"
#include "operator.h"

using namespace std;

class NotQuery : public Query_base
{
  friend Query operator~(const Query&);

  NotQuery(Query q);

  set<line_no> eval(const TextQuery&) const;

  ostream& display(ostream& os) const
  {
    return os << "~(" << query << ")";
  }

  const Query query;
};
#endif
