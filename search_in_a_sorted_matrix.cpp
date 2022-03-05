#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, target;
    cin >> n >> m >> target;
    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    bool check = false;
    int r = 0, c = m - 1;
    while (r < n && c >= 0)
    {
        if (mat[r][c] == target)
        {
            check = true;
            return 0;
        }
        else if (mat[r][c] > target)
        {
            c--;
        }
        else
            r++;
    }

    if (check)
    {
        cout << "Element is found" << endl;
    }
    else
        cout << "Element is not found" << endl;
    return 0;
}
