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
    if (ch == ans[0])
    {
        return ans;
    }
    else
    {
        return ch + ans;
    }
}
int main()
{
    cout << func("aaaaagdgbbbdfffjkll") << endl;
    return 0;
}
