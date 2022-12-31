#include <bits/stdc++.h>
using namespace std;

int reversArr(int arr[], int i, int n)
{
    if (i >= n / 2)
    {
        return 0;
    }
    else
    {
        swap(arr[i], arr[n - i - 1]);
        reversArr(arr, i + 1, n);
    }
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
    reversArr(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}