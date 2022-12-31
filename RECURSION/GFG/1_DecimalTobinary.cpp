#include <bits/stdc++.h>
using namespace std;

void binaryNum(int n)
{
    if (n == 0)
    {
        return;
    }
    binaryNum(n / 2);
    cout << n % 2 << " ";
}
int main()
{
    int n;
    cin >> n;

    binaryNum(n);
    return 0;
}