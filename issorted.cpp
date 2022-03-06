#include <bits/stdc++.h>
using namespace std;

bool solve1(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    bool check = solve1(arr + 1, n - 1);
    return (arr[0] < arr[1] && check);
}

void solve2()
{
}
int main()
{
    int arr[] = {1, 2, 8, 4, 5};
    int n = 5;
    cout << solve1(arr, n) << endl;
    return 0;
}
