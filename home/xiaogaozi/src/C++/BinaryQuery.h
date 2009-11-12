// -1156203886

#ifndef BINARYQUERY_H
#define BINARYQUERY_H
#include <iostream>
#include "Query.h"
#include "Query_base.h"
#include "operator.h"

using namespace std;

class BinaryQuery : public Query_base
{
 protected:
  BinaryQuery(Query, Query, string);

  ostream& display(ostream& os) const
  {
    return os << "(" << lhs << " " << oper << " " << rhs << ")";
  }

  const Query lhs, rhs;
  const string oper;
};
#endif
