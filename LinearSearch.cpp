#include <bits/stdc++.h>
using namespace std;
int LinearSearch(int Arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] == k)
            return i;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    int key;
    cin >> key;

    int index = LinearSearch(Arr, n, key);
    cout << "The element is at index--> " << index;

    return 0;
}

/*input-->n=5
arr= 10 20 30 40 50
key= 20
output-> element is present at index 1;..
*/
