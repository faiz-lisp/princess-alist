// -1156203886

#ifndef ANDQUERY_H
#define ANDQUERY_H
#include <set>
#include "Query.h"
#include "TextQuery.h"
#include "BinaryQuery.h"
#include "operator.h"

using namespace std;

class AndQuery : public BinaryQuery
{
  friend Query operator&(const Query&, const Query&);

  AndQuery(Query, Query);

  set<line_no> eval(const TextQuery&) const;
};
#endif
