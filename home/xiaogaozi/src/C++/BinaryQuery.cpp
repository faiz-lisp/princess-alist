// -1156203886

#include <string>
#include "BinaryQuery.h"
#include "Query.h"

using namespace std;

BinaryQuery::BinaryQuery(Query left, Query right, string op)
  : lhs(left), rhs(right), oper(op)
{
}
