#include "StringUtils.hpp"

using namespace std;

vector<string> TstBits::StringUtils::SplitString(const char* line, char delim, int repeat)
{
    vector<string> tokens;
    string str = "";
    int len = strlen(line);
    for (int i = 0; i < len; i++)
    {
        if (line[i] == delim && str.length() > 0)
        {
            tokens.push_back(str);
            str = "";
        }
        else str += line[i];
    }
    tokens.push_back(str);

    return tokens;
}