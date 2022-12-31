#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;

vector<int>col;
bool dfs(int src , int color , vector<int>&col , vector<int>adj[])
{
   col[src] = color;

   for (auto child : adj[src])
   {
      if (col[child] == -1)
      {
         if (dfs(child , !color , col , adj ) == false)
         {
            return false;
         }
      }
      else if (col[child] == color)
      {
         return false;
      }
   }

   return true;
}
int main()
{
   int n , m ;
   cin >> n >> m ;

   vector<int>adj[n + 1];
   col = vector<int>(n , -1);

   for (int i = 0; i < m; ++i)
   {
      int u , v ;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }


   for (int i = 0 ; i < n ; i++)
   {
      if (col[i] == -1)
      {
         if (dfs(i , 0 , col , adj) == false)
         {
            cout << "False" << endl;
            return 0;
         }
      }
   }


   cout << "YES" << endl;

}