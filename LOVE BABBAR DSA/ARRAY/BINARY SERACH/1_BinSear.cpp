#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vect;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vect.push_back(a);
    }

    int l = 0;
    int h = n - 1;

    int key;

    cin >> key;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (vect[mid] == key)
        {
            cout << mid;
            break;
        }

        else if (key > vect[mid])
        {
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
}