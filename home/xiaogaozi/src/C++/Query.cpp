// -1156203886

#include <iostream>
#include "Query.h"

use namespace std;

Query::Query(const string& s): q(new WordQuery(s))
{
}

Query::Query(const Query& c): q(c.q), use(c.use)
{
  ++*use;
}

Query::Query(Query_base* query): q(query), use(new size_t(1))
{
}
