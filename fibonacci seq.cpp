#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    else
    {
        return solve(n - 1) + solve(n - 2);
    }
}
int main()
{
    int n, i = 0;
    cin >> n;
    while (i < n)
    {
        cout << " " << solve(i);
        i++;
    };
    return 0;
}

/*input-15
output--
 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377*/
