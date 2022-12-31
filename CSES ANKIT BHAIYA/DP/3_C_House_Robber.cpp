#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;


int main()
{
   int n ;
   cin >> n ;

   vector<int>v(n);
   for (int i = 0; i < n; ++i)
   {
      cin >> v[i];
   }
   if(n==1)
   {
       cout<<0<<endl;
       return 0 ;
   }
   vector<int>dp(n + 1 , 0 );
   dp[0] = v[0];
   dp[1] = max(v[1] , v[0]);

   for (int i = 2 ; i < n ; i++)
   {
      dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
   }
   cout << dp[n - 1];
   return 0 ;
}