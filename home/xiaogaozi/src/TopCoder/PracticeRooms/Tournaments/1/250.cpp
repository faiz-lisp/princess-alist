#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

class HowEasy
{
public:
    int pointVal(string param0)
    {
        istringstream stream(param0);
        string word;
        int words_num = 0, letters_num = 0;
        while (stream >> word)
        {
            int tmp = 0;
            string::size_type index;
            for (index = 0; index != word.size(); ++index)
            {
                if (isalpha(word[index]) || word[index] == '.')
                    ++tmp;
                else
                    break;
            }

            if (index != word.size())
                continue;

            letters_num += tmp;
            ++words_num;
        }

        int avg_word_len;
        if (words_num == 0)
            avg_word_len = 0;
        else
            avg_word_len = letters_num / words_num;

        int point;
        if (avg_word_len <= 3)
            point = 250;
        else if (avg_word_len == 4 || avg_word_len == 5)
            point = 500;
        else
            point = 1000;

        return point;
    }
};

int main()
{
    HowEasy a;
    ifstream infile;
    infile.open("250_input");
    string line;

    while (getline(infile, line))
    {
        cout << line << endl;
        cout << "Point: " << a.pointVal(line) << endl;
    }

    infile.close();

    return 0;
}
