#include<bits/stdc++.h>
using namespace std ;
#define ll long long int

void bfs(int row , int col , vector<vector<int>>&vis , vector<vector<char>>&grid)
{
	// mark it visited
	vis[row][col] = 1;
	queue<pair<int, int>> q;
	// push the node in queue
	q.push({row, col});
	int n = grid.size();
	int m = grid[0].size();

	// until the queue becomes empty
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		/* // traverse in the neighbours and mark them if its a land
		 for(int delrow = -1; delrow<=1;delrow++) {
		     for(int delcol = -1; delcol <= 1; delcol++) {
		         int nrow = row + delrow;
		         int ncol = col + delcol;
		         // neighbour row and column is valid, and is an unvisited land
		         if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
		         && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
		             vis[nrow][ncol] = 1;
		             q.push({nrow, ncol});
		         }
		     }
		 }
		*/

		if (row - 1 >= 0  and grid[row - 1][col] == '.' and !vis[row - 1][col])
		{
			vis[row - 1][col] = 1;
			q.push({row - 1, col});
		}
		if (row + 1 < n  and grid[row + 1][col] == '.' and !vis[row + 1][col])
		{
			vis[row + 1][col] = 1;
			q.push({row + 1, col});
		} if (col - 1 >= 0  and grid[row][col - 1] == '.' and !vis[row][col - 1])
		{
			vis[row][col - 1] = 1;
			q.push({row, col - 1});
		} if (col + 1 < m  and grid[row][col + 1] == '.' and !vis[row][col + 1])
		{
			vis[row][col + 1] = 1;
			q.push({row, col + 1});
		}
	}

}
int main()
{
	int n , m ;
	cin >> n >> m ;

	vector<vector<char>>v(n, vector<char>(m, 0));


	for (int i = 0 ; i < n; i++)
	{
		for (int j = 0 ; j < m ; j++)
		{
			cin >> v[i][j];
		}
	}

	// for (auto  x : v)
	// {
	// 	for (auto y : x )
	// 	{
	// 		cout << y ;
	// 	}
	// 	cout << endl;
	// }

	vector<vector<int>> vis(n, vector<int>(m, 0));
	int cnt = 0;
	for (int row = 0; row < n ; row++) {
		for (int col = 0; col < m ; col++) {
			// if not visited and is a land
			if (!vis[row][col] && v[row][col] == '.') {
				cnt++;
				bfs(row, col, vis, v);
			}
		}
	}


	cout << cnt << endl;

	return 0 ;
}