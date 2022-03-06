#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int j = 0, i = 0, st = 0, ed = 0, sum = 0;
    while (j < n && sum + arr[j] <= s)
    {
        sum = sum + arr[j];
        j++;
    }
    if (sum == s)
    {
        cout << i + 1 << " " << j << endl;
        return 0;
    }
    while (j < n)
    {
        sum = sum + arr[j];
        while (sum > s)
        {
            sum = sum - arr[i];
            i++;
        }
        if (sum == s)
        {
            st = i + 1;
            ed = j + 1;
        }
        j++;
    }
    cout << st << " " << ed << endl;

    return 0;
}
//...
