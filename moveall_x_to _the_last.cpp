#include <bits/stdc++.h>
using namespace std;
string func(string str)
{
    if (str.length() == 0)
    {
        return "";
    }
    char ch = str[0];
    string ans = func(str.substr(1));
    if (ch == 'x')
    {
        return ans + ch;
    }
    else
    {
        return ch + ans;
    }
}
int main()
{
    cout << func("xxxdfsxxxdfxxfdssss") << endl;
    return 0;
}
