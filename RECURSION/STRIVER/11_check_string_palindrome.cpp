#include <bits/stdc++.h>
using namespace std;

bool checkString(string s, int i, int n)
{
    if (i >= n / 2)
    {
        return true;
    }
    else
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
        checkString(s, i + 1, n);
    }

    return true;
}
int main()
{
    string s;
    cin >> s;
    int n = s.size();
   cout<< checkString(s, 0, n);
}