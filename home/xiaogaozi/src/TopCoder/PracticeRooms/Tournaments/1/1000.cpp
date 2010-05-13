/*
 * <one line to give the program's name and a brief idea of what it does.> <project url>
 * Copyright (C) <year>  xiaogaozi <gaochangjian@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class ClassesCompare
{
public:
    bool operator()(const string& lhs, const string& rhs) const
    {
        string lname = lhs.substr(0, lhs.size() - 3);
        string rname = rhs.substr(0, rhs.size() - 3);
        string lnum = lhs.substr(lhs.size() - 3);
        string rnum = rhs.substr(rhs.size() - 3);

        if (lnum != rnum)
            return lnum < rnum;
        else
            return lname < rname;
    }
};

class Prerequisites
{
public:
    vector<string> orderClasses(vector<string> param0)
    {
        vector<string> v;
        typedef multimap<int, string>::iterator iter1;
        typedef multimap<string, string>::iterator iter2;

        parse(param0);
        while (mm1.size())
        {
            pair<iter1, iter1> pos = mm1.equal_range(0);
            if (pos.first != pos.second)  // found
            {
                set<string, ClassesCompare> s;
                while (pos.first != pos.second)
                {
                    s.insert(pos.first->second);
                    ++pos.first;
                }

                set<string, ClassesCompare>::iterator i = s.begin();
                v.push_back(*i);
                mm2.erase(*i);
                for (iter2 j = mm2.begin(); j != mm2.end(); ++j)
                    if (j->second == *i)
                        mm2.erase(j);

                mm1.clear();
                string tmp = "";
                for (iter2 j = mm2.begin(); j != mm2.end(); ++j)
                {
                    if (j->first != tmp)
                    {
                        tmp = j->first;
                        mm1.insert(make_pair(mm2.count(j->first) - 1,
                                             j->first));
                    }
                    else
                        continue;
                }
            }
            else  // not found
            {
                v.clear();
                break;
            }
        }

        return v;
    }

private:
    multimap<int, string> mm1;
    multimap<string, string> mm2;

    void parse(vector<string> v)
    {
        vector<string>::iterator iter;
        for (iter = v.begin(); iter != v.end(); ++iter)
        {
            vector<string> v1 = split(*iter, ':');
            if (v1[1] != "")
            {
                vector<string> v2 = split(v1[1].substr(1));
                mm1.insert(make_pair(v2.size(), v1[0]));
                vector<string>::iterator i;
                for (i = v2.begin(); i != v2.end(); ++i)
                    mm2.insert(make_pair(v1[0], *i));
            }
            else
            {
                mm1.insert(make_pair(0, v1[0]));
            }
            mm2.insert(make_pair(v1[0], ""));
        }
    }

    vector<string> split(const string s, char delim = ' ')
    {
        vector<string> elems;
        istringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            elems.push_back(item);
        }
        if (item == "")
            elems.push_back(item);
        return elems;
    }
};

int main(int argc, char* argv[])
{
    ifstream infile;
    infile.open("1000_input");
    string line;
    vector<string> vec1;
    vector<string> vec2;

    while (getline(infile, line))
        vec1.push_back(line);

    Prerequisites obj;
    vec2 = obj.orderClasses(vec1);
    for (vector<string>::iterator i = vec2.begin();
         i != vec2.end(); ++i)
        cout << *i << endl;

    infile.close();

    return 0;
}
