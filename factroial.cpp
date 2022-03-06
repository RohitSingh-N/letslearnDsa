#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    // base case
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return (n * fact(n - 1));
    }
}
int main()
{
    int n;
    cin >> n;
    int factorial = fact(n);
    cout << factorial;
    return 0;
}

/*input-->5.
output-->120 */
