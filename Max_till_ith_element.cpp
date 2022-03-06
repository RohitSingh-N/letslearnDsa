#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    int currmax = 0;
    int totalmax = 0;
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] > Arr[i + 1])
            currmax = Arr[i];
        if (currmax > totalmax)
            totalmax = currmax;
    }
    cout << "The maximum is --> " << totalmax;
    return 0;
}
// .6
// 1 5 8 6 3 4
