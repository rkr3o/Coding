#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int>adj[N];
int vis[N];
int level[N];
int p[N];

void bfs(int source)
{
     queue<int> q;
     q.push(source);
     vis[source] = 1;
     p[source]=-1;
     while (!q.empty())
     {
          int cur = q.front();
          q.pop();

          cout << "Indxe " <<cur << " ";

          for (auto child : adj[cur])
          {
               if (!vis[child])
               {
                    q.push(child);
                    vis[child] = 1;
                    level[child] = level[cur] + 1;
                    p[child]=cur;
               }
          }
          
          // restore the path 
          if (!vis[cur])
          {
               cout << "No path!";
          }
          else
          {
               vector<int> path;
               for (int v = cur; v != -1; v = p[v])
                    path.push_back(v);
               reverse(path.begin(), path.end());
               cout << "Path: ";
               for (int v : path)
                    cout << v << " ";
          }
      
     }
}
int main()
{
     int n, m;
	cin >> n >> m;

	for (int i = 0; i < m - 1; i++)
	{
		int cur, v;
		cin >> cur >> v;

		adj[cur].push_back(v);
		adj[v].push_back(cur);
	}

	bfs(1);
	cout << endl;
	for (int i = 1; i <= m; i++)
	{
		cout << i << " " << level[i] << " " << endl;
	}
     
}