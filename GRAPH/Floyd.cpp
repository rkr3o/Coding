#include<bits/stdc++.h>
using namespace std ;

#define endl "\n"
#define ll long long int
const int mod = 1e9 + 7;
int cnt = 0 ;
const int N = 1e3 + 10;

// floyd warshall algorithm

int main()
{

	vector<vector<int>>dist(N, vector<int>(N));

	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			} else {
				dist[i][j] = 1e9;
			}
		}
	}


	int n , m ;
	cin >> n >> m ;

	for (int i = 0 ; i < m ; i++)
	{
		int u , v, wt ;
		cin >> u >> v >> wt;

		dist[u][v] = wt;

	}

	for (int k = 1 ; k <= n ; k++)
	{
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= n ; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			if (dist[i][j] == 1e9)
			{
				cout << "I" << " ";
			} else {
				cout << dist[i][j] << " ";
			}
		}
		cout << endl;
	}


	return 0 ;
}
