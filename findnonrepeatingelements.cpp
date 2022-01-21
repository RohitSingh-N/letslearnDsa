#include <bits/stdc++.h>
using namespace std;
void get2twonon_repeatingpos(int arr[], int n, int *a, int *b)
{
    int Xor = arr[0];
    int no_of_bits;
    *a = 0;
    *b = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        Xor ^= arr[i];
    }
    no_of_bits = Xor & ~(Xor - 1);

    for (i = 0; i < n; i++)
    {
        if (arr[i] & no_of_bits)
        {
            *a = *a ^ arr[i];
        }
        else
        {
            *b = *b ^ arr[i];
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(*arr);
    int *a = new int[(sizeof(int))];
    int *b = new int[(sizeof(int))];
    get2twonon_repeatingpos(arr, n, a, b);
    cout << "The non-repeating elements are " << *a
         << " and " << *b;
}