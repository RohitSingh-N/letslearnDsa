#include <bits/stdc++.h>
using namespace std;
int kadane(int arr[], int n)
{
    int currsum = -0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum < 0)
        {
            currsum = 0;
        }
        maxsum = max(currsum, maxsum);
    }
    return maxsum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int wrappedsum, nonwrapped;
    nonwrapped = kadane(arr, n);
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrappedsum = totalsum + kadane(arr, n);

    cout << max(wrappedsum, nonwrapped) << endl;
    return 0;
}
