// lets start graph guyzzzzzzzzzzzzz

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3+10;
int adj[N][N];
int main()
{
	int n , m ;
	cin >> n >> m ;

	//vector<vector<int>>adj(n + 2, vector<int>(m + 2, 0));
	
	for (int i = 0; i < m; i++)
	{
		int u , v ;
		cin >> u >> v ;
		adj[v][u] = 1 ;
		adj[u][v] = 1 ;

	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1 ;  j <= n; ++j)
		{
			cout << adj[i][j] << " ";
		}

		cout << endl;
	}


}