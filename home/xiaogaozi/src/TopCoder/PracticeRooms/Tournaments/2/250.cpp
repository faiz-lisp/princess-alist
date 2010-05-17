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

using namespace std;

class Compare
{
public:
    bool operator()(const int& lh, const int& rh) const
    {
        return rh - lh;
    }
};

class MatchMaker
{
public:
    vector<string> getBestMatches(vector<string> param0, string param1, int param2)
    {
        vector< vector<string> > vv;
        vector<string> answers;
        string gender;
        multimap<int, string, Compare> mm;

        for (vector<string>::iterator i = param0.begin();
             i != param0.end(); ++i)
        {
            vector<string> v = split(*i);
            vv.push_back(v);
            if (v[0] == param1)
            {
                gender = v[2];
                answers = vector<string>(v.begin(), v.end());
            }
        }

        int count = 0;
        for (vector< vector<string> >::iterator i = vv.begin();
             i != vv.end(); ++i, count = 0)
        {
            if ((*i)[1] == gender && (*i)[0] != param1)
            {
                for (vector<string>::size_type j = 3; j != i->size(); ++j)
                    if ((*i)[j] == answers[j])
                        ++count;
                if (count >= param2)
                    mm.insert(make_pair(count, (*i)[0]));
            }
        }

        vector<string> result;
        for (multimap<int, string, Compare>::iterator i = mm.begin();
             i != mm.end(); ++i)
            result.push_back(i->second);

        return result;
    }

private:
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
    infile.open("250_input");
    string line;
    vector<string> vec1;
    vector<string> vec2;

    while (getline(infile, line))
        vec1.push_back(line);

    MatchMaker obj;
    vec2 = obj.getBestMatches(vec1, "MARGE", 4);
    for (vector<string>::iterator i = vec2.begin();
         i != vec2.end(); ++i)
        cout << *i << endl;

    infile.close();

    return 0;
}
