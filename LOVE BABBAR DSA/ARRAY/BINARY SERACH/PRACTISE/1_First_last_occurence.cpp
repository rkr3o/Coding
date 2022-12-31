// write a program to find the key by using BINARY SEARCH
#include <iostream>
using namespace std;

int lucifer(int arr[], int n, int key)
{
    int l = 0, h = n - 1, mid;
    int ans = 0;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (key > arr[mid])
        {
            l = mid + 1;
        }
        else if (key < arr[mid])
        {
            h = mid - 1;
        }
    }

    return ans;
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
    cout << "Your key : ";
    int key;
    cin >> key;

    cout << lucifer(arr, n, key);
}