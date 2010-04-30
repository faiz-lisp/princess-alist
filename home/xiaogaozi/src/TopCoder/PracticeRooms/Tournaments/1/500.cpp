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
#include <algorithm>

using namespace std;

class SquareDigits
{
public:
    int smallestResult(int param0)
    {
        int x = 0;
        int n = param0;
        vector<int> vec;

        if (n == 0)
            return 0;
        else if (n > 0)
        {
            while (1)
            {
                ++x;
                vec.clear();
                int tmp = x;

                while ((tmp = S(tmp)) != n)
                {
                    if (count(vec.begin(), vec.end(), tmp) == 0)
                        vec.push_back(tmp);
                    else
                        break;
                }

                if (tmp == n)
                    return x;
            }
        }
        else
            return -1;
    }

    int S(int x)
    {
        int sum = 0;

        while (x != 0)
        {
            int digit = x % 10;
            sum += digit * digit;
            x = x / 10;
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    SquareDigits obj;
    ifstream infile;
    infile.open("500_input");
    string line;

    while (getline(infile, line))
    {
        int i;
        istringstream iss(line);
        iss >> i;
        cout << "x: " << obj.smallestResult(i) << endl;
    }

    infile.close();

    return 0;
}
