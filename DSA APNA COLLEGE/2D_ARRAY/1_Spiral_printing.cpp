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

    // spiral print
    /*
    1 5 7 9 10 11
    6 10 12 13 20 21
    9 25 29 30 32 41
    15 55 59 63 68 70
    40 70 79 81 95 105
     */
    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = m - 1;

    while (rowStart <= rowEnd and colStart <= colEnd)
    {
        // for starting row
        for (int col = colStart; col <= colEnd; col++)
        {
            cout << arr[rowStart][col] << " ";
        }
        rowStart++;
        // for column end

        for (int row = rowStart; row <= rowEnd; row++)
        {
            cout << arr[row][colEnd] << " ";
        }
        colEnd--;

        // for row end

        for (int col = colEnd; col >= colStart; col--)
        {
            cout << arr[rowEnd][col] << " ";
        }
        rowEnd--;
        // for col start
        for (int row = rowEnd; row >= rowStart; row--)
        {
            cout << arr[row][colStart] << " ";
        }

        colStart++;
    }
}