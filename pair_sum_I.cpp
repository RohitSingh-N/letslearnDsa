#include <bits/stdc++.h>
using namespace std;
bool solve(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low << " " << high << endl;
            return true;
        }
        else if (arr[low] + arr[high] > k)
            high--;
        else
            low++;
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool check = solve(arr, n, k);
    if (check)
    {
        cout << "Element are present" << endl;
    }
    else
    {
        cout << "Element are not present" << endl;
    }

    return 0;
}
