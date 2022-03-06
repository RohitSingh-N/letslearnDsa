#include <bits/stdc++.h>
using namespace std;
int func(int arr[], int n, int i, int k)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == k)
    {
        return i;
    }
    return func(arr, n, i + 1, k);
}
int func1(int arr[], int n, int i, int k)
{
    if (i == n)
    {
        return -1;
    }
    int restarray = func1(arr, n, i + 1, k);
    if (restarray != -1)
    {
        return restarray;
    }
    if (arr[i] == k)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[] = {7, 2, 1, 2, 5, 1, 7};
    int n = 7;
    int key = 1;
    cout << func(arr, n, 0, key) << endl;
    cout << func1(arr, n, 0, key) << endl;
    return 0;
}
