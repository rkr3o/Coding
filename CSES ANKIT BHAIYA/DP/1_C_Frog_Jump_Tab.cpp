#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;


int main()
{
   ll n ;
   cin >> n ;
   vector<ll>jumps(n);
   vector<int>dp(n + 1 , 0);
   for (int i = 0; i < n; ++i)
   {
      cin >> jumps[i];
   }

   dp[1] = abs(jumps[1] - jumps[0]);

   for (int i = 2; i < n ; i++)
   {
      dp[i] = min(abs(jumps[i] - jumps[i - 1]) + dp[i - 1], abs(jumps[i] - jumps[i - 2]) + dp[i - 2]);
   }

   cout << dp[n - 1];
   return 0 ;
}