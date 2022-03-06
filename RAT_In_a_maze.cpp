#include <bits/stdc++.h>
using namespace std;
bool issafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ratinmaze(int **arr, int x, int y, int n, int **solarray)
{
    if (x == (n - 1) && y == (n - 1))
    {
        solarray[x][y] = 1;
        return true;
    }

    if (issafe(arr, x, y, n))
    {
        solarray[x][y] = 1;
        if (ratinmaze(arr, x + 1, y, n, solarray))
            return true;
        if (ratinmaze(arr, x, y + 1, n, solarray))
            return true;
        return false;
        solarray[x][y] = 0;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int **solarray = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solarray[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solarray[i][j] = 0;
        }
    }
    if (ratinmaze(arr, 0, 0, n, solarray))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solarray[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/*
5
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
o/p-->
1 0 0 0 0 
1 1 1 1 0 
0 1 0 1 0 
0 0 0 1 1 
0 0 0 0 1

inp-->
5
1 1 1 0 1
1 1 1 1 1
0 0 0 1 0
1 0 0 1 1
1 1 1 0 1


o/p-->
1 0 0 0 0 
1 1 1 1 0 
0 0 0 1 0 
0 0 0 1 1 
0 0 0 0 1

*/
