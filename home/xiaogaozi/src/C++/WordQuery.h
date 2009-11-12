// -1156203886

#ifndef WORDQUERY_H
#define WORDQUERY_H
#include <iostream>
#include <set>
#include "TextQuery.h"
#include "Query_base.h"

using namespace std;

class WordQuery : public Query_base
{
  friend class Query;

  WordQuery(const string&);

  set<line_no> eval(const TextQuery& t) const
  {
    return t.run_query(query_word);
  }

  ostream& display(ostream& os) const
  {
    return os << query_word;
  }

  string query_word;
};
#endif
