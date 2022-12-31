#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;

int solve(vector<vector<int>>&v , int currow , int curcol)
{
   if (curcol < 0 || curcol >= v[0].size())
   {
      return INT_MIN;
   }
   if (currow == v.size() - 1)
   {
      return v[currow][curcol];
   }
   int down = solve(v, currow + 1 , curcol);
   int dleft = solve(v, currow + 1 , curcol - 1);
   int dright = solve(v, currow + 1, curcol + 1);

   return v[currow][curcol] + max(down , max(dleft, dright));
}
int main()
{

   int n , m ;
   cin >> n >> m ;
   vector<vector<int>>v(n, vector<int>(m));
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < m; ++j)
      {
         cin >> v[i][j];
         
      }
   }

   cout << solve(v, 0, 0);
   return 0 ;
}