#include<bits/stdc++.h>
using namespace std ;
#define ll long long int


// from all direction using bfs

void bfs(int row , int col , vector<vector<int>>&vis , vector<vector<int>>&v)
{
	int n = v.size();
	int m = v[0].size();
	queue<pair<int , int>>q ;
	q.push({row, col});
	vis[row][col] = 1;

	

	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;

		q.pop();


		// traverse in the neighbours
		for (int delrow = -1 ; delrow <= 1 ; delrow++)
		{
			for (int delcol = -1 ; delcol <= 1 ; delcol++)
			{
				int  nrow = row + delrow;
				int ncol = col + delcol;

				// these variable should be valid so check

				if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and  v[row][col] == 1 and !vis[nrow][ncol])
				{
					vis[nrow][ncol] = 1;
					q.push({nrow , ncol});
				}
			}
		}

	}

}
int main()
{
	int n , m ;
	cin >> n >> m ;

	vector<vector<int>>v(n , vector<int>(m, 0));

	for (int i = 0 ; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}

	// create a visited array
	vector<vector<int>>vis(n, vector<int>(m, 0));
	int cnt = 0 ;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{

			if (!vis[i][j] and v[i][j] == 1)
			{
				cnt++;
				bfs(i, j, vis, v);
			}
		}
	}


	cout << cnt << endl;


	for (auto x : v)
	{
		for (auto y : x )
		{
			cout << y << " ";
		}
		cout << endl;
	}
	return 0 ;
}