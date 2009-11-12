// -1156203886

#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include <iostream>
#include <set>
#include "TextQuery.h"

using namespace std;

class Query_base
{
  friend class Query;

 protected:
  typedef TextQuery::line_no line_no;
  virtual ~Query_base() {}

 private:
  virtual set<line_no> eval(const TextQuery&) const = 0;
  virtual ostream& display(ostream& = cout) const = 0;
};
#endif
