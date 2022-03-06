#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int n, int k)
{
    int low = 0;
    int high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }

        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
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
    int key;
    cin >> key;

    int index = BinarySearch(arr, n, key);
    cout << "The element is at index--> " << index;
    return 0;
}
//...
