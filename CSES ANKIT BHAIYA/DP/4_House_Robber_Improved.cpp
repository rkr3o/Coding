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
   int prev_ans2=v[0], prev_ans=max(v[0],v[1]),curr_ans=prev_ans;
        
        for(int i = 2; i < n; i++){
            curr_ans = max(prev_ans, prev_ans2 + v[i]);
            prev_ans2 = prev_ans;
            prev_ans = curr_ans;
        }
        cout<< curr_ans<<endl;
    
}