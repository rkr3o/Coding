#include<bits/stdc++.h>
using namespace std ;

#define endl "\n"
#define ll long long int
const int mod = 1e9 + 7;
int cnt = 0 ;
const int N = 1e3 + 10;

int main()
{

	vector<vector<int>>dist(N, vector<int>(N));
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ;  j < N ; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			} else {
				dist[i][j] = INT_MAX;
			}
		}
	}
	int n , m ;
	cin >> n >> m ;
	for (int i = 0 ; i < m ; i++)
	{
		int u , v , wt;
		cin >> u >> v >> wt ;
		dist[u][v] = wt;
		dist[v][u] = wt;
	}
	int th ;
	cin >> th;
	for (int k = 0 ; k < n ; k++)
	{
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int cities = n;
	int city = -1;

	for (int i = 0 ; i < n ; i++)
	{
		int cnt = 0;
		for (int j = 0 ; j < n ; j++)
		{
			if (dist[i][j] <= th)
			{
				cnt++;
			}
		}

		if (cnt <= cities)
		{
			cities = cnt;
			city = i;
		}
	}
	cout << city << endl;
	return 0 ;
}
