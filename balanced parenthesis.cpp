#include <bits/stdc++.h>
using namespace std;
bool func(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (st.size() != 0)
        {
            char elem = st.top();
            st.pop();
            if (s[i] == '}' && elem != '{')
            {
                return false;
            }
            else if (s[i] == ']' && elem != '[')
            {
                return false;
            }
            else if (s[i] == ')' && elem != '(')
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    if (st.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cout << func("[{())}]");
    return 0;
}
