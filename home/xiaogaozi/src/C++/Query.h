// -1156203886

#ifndef QUERY_H
#define QUERY_H
#include <iostream>
#include <set>
#include "TextQuery.h"
#include "Query_base.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"

using namespace std;

class Query
{
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);

 public:
  Query(const string&);
  Query(const Query&);
  ~Query()
  {
    decr_use();
  }

  set<TextQuery::line_no> eval(const TextQuery& t) const
  {
    return q->eval(t);
  }

  ostream& display(ostream& os) const
  {
    return q->display();
  }

 private:
  Query_base* q;
  size_t* use;

  Query(Query_base* query);
  void decr_use()
  {
    if (--*use == 0)
    {
      delete q;
      delete use;
    }
  }
};
#endif
