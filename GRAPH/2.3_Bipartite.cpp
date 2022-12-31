#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;

vector<int>col;
bool bfs(int src , vector<int>&col , vector<int>adj[])
{
   queue<int>q;
   q.push(src);
   col[src] = 0 ;

   while (!q.empty())
   {
      int cur = q.front();
      q.pop();

      for (auto child : adj[cur])
      {
         if (col[child] == -1)
         {
            q.push(child);
            col[child] = col[cur] ^ 1;
         }
         else if (col[child] == col[cur])
         {
            return false;
         }
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
         if (bfs(i , col , adj) == false)
         {
            cout << "False" << endl;
            return 0;
         }
      }
   }


   cout << "YES" << endl;

}