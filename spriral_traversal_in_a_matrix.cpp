#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Printing the matrix in normal order -->" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Printing the matrix in spiral order -->" << endl;
    int row_start = 0, row_end = n - 1, col_Start = 0, col_end = m - 1;
    while (row_start <= row_end && col_Start <= col_end)
    {
        // for printing first row
        for (int col = col_Start; col <= col_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }

        row_start++;
        cout << endl;
        // for printing last col
        for (int row = row_start; row <= row_end; row++)
        {
            cout << arr[row][col_end] << " ";
        }

        col_end--;
        cout << endl;
        // for printing last row

        for (int col = col_end; col >= col_Start; col--)
        {
            cout << arr[row_end][col] << " ";
        }

        row_end--;
        cout << endl;
        // for printing first col

        for (int row = row_end; row >= row_start; row--)
        {
            cout << arr[row][col_Start] << " ";
        }

        col_Start++;
        cout << endl;
    }

    return 0;
}


//input-->
// 5 6
// 1 5 7 9 10 6 10 12 13 20 21 9 25 29 30 32 41 15 55 59 63 68 70 40 70 79 81 95 105
//output-->
// Printing the matrix in normal order -->
// 1 5 7 9 10 6 
// 10 12 13 20 21 9 
// 25 29 30 32 41 15 
// 55 59 63 68 70 40 
// 70 79 81 95 105 0 
// Printing the matrix in spiral order -->
// 1 5 7 9 10 6 
// 9 15 40 0 
// 105 95 81 79 70 
// 55 25 10 
// 12 13 20 21 
// 41 70 
// 68 63 59 
// 29 
// 30 32 

// 30
