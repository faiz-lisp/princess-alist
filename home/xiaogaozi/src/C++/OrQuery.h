// -1156203886

#ifndef ORQUERY_H
#define ORQUERY_H
#include <set>
#include "Query.h"
#include "TextQuery.h"
#include "BinaryQuery.h"
#include "operator.h"

using namespace std;

class OrQuery : public BinaryQuery
{
  friend Query operator|(const Query&, const Query&);

  OrQuery(Query, Query);

  set<line_no> eval(const TextQuery&) const;
};
#endif
