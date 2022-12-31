//find the connected components and store the components

#include<bits/stdc++.h>
using namespace std ;
#define ll long long int

vector<vector<int>>cc;
vector<int>curent_cc;

void dfs(int source , bool vis[], vector<int>adj[])
{

	vis[source] = true;
	curent_cc.push_back(source);

	for (int x : adj[source])
	{
		if (!vis[x])
		{
			dfs(x, vis, adj);
		}
	}
}

int main()
{
	int n , m ;
	cin >> n >> m ;

	vector<int>adj[n + 1];
	bool vis[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int u  , v ;
		cin >> u >> v ;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt = 0 ;
	// run dfs for each node : 1 3 5 6 2 4
	for (int i = 1 ; i <= n; ++i)
	{
		if (!vis[i])
		{
			curent_cc.clear();
			cnt++;
			dfs(i, vis, adj);

			cc.push_back(curent_cc);
		}
	}
	cout << cnt << endl;

	for (auto c_cc : cc)
	{
		for (int  x : c_cc)
		{
			cout << x << " ";
		}

		cout << endl;

	}
	return 0 ;
}

/*
to store the connected components :
1 : clear the current components before calling dfs
2 : After geeting all the elements of current components then push it to main cc
3 : everytime store the vertex in current xomponent list in dfs*/