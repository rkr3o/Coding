#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int N = 1e3 + 10;
vector<int>adj[N];
vector<bool>vis(N);
vector<int>level(N, 0);

void dfs(int source)
{
	cout << source << " ";

	vis[source] = true;

	for (int x : adj[source])
	{
		if (!vis[x])
		{
			dfs(x);
		}
	}
}

int main()
{
	int n , m ;
	cin >> n >> m ;

	for (int i = 0; i < m; ++i)
	{
		int u  , v ;
		cin >> u >> v ;

		adj[u].push_back(v);
		//adj[v].push_back(u);
	}

// run dfs for each node
	for (int i = 1 ; i <= n; ++i)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}


	return 0 ;
}