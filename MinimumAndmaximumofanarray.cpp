#include <iostream>
using namespace std;
struct Pair
{
    int min = 0;
    int max = 0;
};
struct Pair getminmax(int arr[], int low, int high)
{
    struct Pair minmax, mmr, mml;
    int mid;
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];
    }
    if (high = low + 1)
    {
        if (arr[high] > arr[low])
        {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        else
        {
            minmax.min = arr[high];
            minmax.max = arr[low];
        }
    }
    mid = (low + high) / 2;
    getminmax(arr, low, mid);
    getminmax(arr, mid + 1, high);

    if (mmr.min > mml.min)
    {
        minmax.min = mml.min;
    }
    else
    {
        minmax.min = mmr.min;
    }
    if (mmr.max > mml.max)
    {
        minmax.max = mmr.max;
    }
    else
    {
        minmax.max = mml.max;
    }

    return minmax;
}
int main()
{
    // int arr[5] = {4, 5, 8, 2, 1};
    // int arr[1] = {8};
    // int arr[3] = {-1, -3, -6};
    int arr[5] = {1,
                  1,
                  1,
                  1,
                  0};
    int n = 5;
    struct Pair minmax = getminmax(arr, 0, n - 1);
    cout << "The maximum element is " << minmax.max << endl;
    cout << "The minimum element is " << minmax.min << endl;
}

/////////////////////////////////////////////////////
// second Approch--> Recursive Approch

//  struct Pair
//  {
//      int min = 0;
//      int max = 0;
//  };

// Pair Peakelement(int arr[], int n)
// {
//     struct Pair minmax;
//     // if the size of array is one
//     if (n == 1)
//         ;
//     {
//         minmax.min = arr[0];
//         minmax.max = arr[0];
//     }
//     // if first element is greater than the second element then adjust their values accordingly
//     if (arr[0] < arr[1])
//     {
//         minmax.min = arr[0];
//         minmax.max = arr[1];
//     }
//     // now run a loop from the second index that is index=2
//     // we are doing so because as we have decided than the max and min are arr[1] and arr[0] respectively
//     for (int i = 2; i < n; i++)
//     {
//         if (arr[i] > minmax.max)
//         {
//             minmax.max = arr[i];
//         }
//         else if (arr[i] < minmax.min)
//         {
//             minmax.min = arr[i];
//         }
//     }
//     return minmax;
// }
// int main()
// {
//     // int arr[5] = {4, 5, 8, 2, 1};
//     // int arr[1] = {8};
//     // int arr[3] = {-1, -3, -6};
//     int arr[5] = {1,
//                   1,
//                   1,
//                   1,
//                   0};
//     int n = 5;
//     struct Pair minmax = Peakelement(arr, n);
//     cout << "The maximum element is " << minmax.max << endl;
//     cout << "The minimum element is " << minmax.min << endl;
// }
// time complexity is O(n)..
