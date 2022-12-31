#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;
const int N = 1e3 + 10;
vector<vector<int>>adj;

int main()
{
   int n , m ;
   cin >> n >> m;
   adj = vector<vector<int>>(n + 1);

   for (int i = 0; i < m; ++i)
   {
      int u , v ;
      cin >> u >> v;
      adj[u].push_back(v)  ;
      adj[v].push_back(u)  ;
   }

   for (int i = 0 ; i < n ; i++)
   {
      for (auto  x : adj[i])
      {
         cout << "this " << i << " is connected" << " " << x << endl;
      }

   }
   return 0 ;
}