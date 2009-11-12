// -1156203886

#include <set>
#include <algorithm>
#include <iterator>
#include "AndQuery.h"
#include "Query.h"
#include "BinaryQuery.h"
#include "TextQuery.h"

using namespace std;

AndQuery::AndQuery(Query left, Query right)
  : BinaryQuery(left, right, "&")
{
}

set<line_no> AndQuery::eval(const TextQuery& file) const
{
  set<line_no> left = lhs.eval(file);
  set<line_no> right = rhs.eval(file);
  set<line_no> ret_lines;

  set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                   inserter(ret_lines, ret_lines.begin()));
}
