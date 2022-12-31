#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int mod = 1e9 + 7;
vector<int>v ;
int solve(int idx , int n )
{

   if (idx > n - 1)
   {
      return mod;

   }

   if (idx == n - 1)
   {
      return 0 ;
   }

   int jump1 =  abs(v[idx + 1] - v[idx]) + solve(idx + 1 , n);
   int jump2 =  abs(v[idx + 2] - v[idx]) + solve(idx + 2, n);

   return min(jump1, jump2);


}
int main()
{

   int n ;
   cin >> n ;
   v = vector <int>(n);

   for (int i = 0; i < n; ++i)
   {
      cin >> v[i];
   }
   cout << solve(0 , n);
   return 0 ;
}