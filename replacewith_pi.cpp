#include <bits/stdc++.h>
using namespace std;
void func(string str)
{
    if (str.length() == 0)
    {
        return;
    }
    if (str[0] == 'p' && str[1] == 'i')
    {
        cout << "3.14";
        func(str.substr(2));
    }
    else
    {
        cout << str[0];
        func(str.substr(1));
    }
}
int main()
{
    func("pippppipippe");
    return 0;
}
