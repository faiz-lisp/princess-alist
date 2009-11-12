// -1156203886

#include <set>
#include "OrQuery.h"
#include "Query.h"
#include "BinaryQuery.h"
#include "TextQuery.h"

using namespace std;

OrQuery::OrQuery(Query left, Query right)
  : BinaryQuery(left, right, "|")
{
}

set<line_no> OrQuery::eval(const TextQuery& file) const
{
  set<line_no> right = rhs.eval(file), ret_lines = lhs.eval(file);

  ret_lines.insert(right.begin(), right.end());
  return ret_lines;
}
