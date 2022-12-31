#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
 
void dfs( vector<vector<char>>&grid , int row , int col )
{
	if ( row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '.')
	{
		return ;
	}
 
 
	grid[row][col] = '2';
	dfs(grid, row + 1, col);
	dfs(grid, row - 1, col);
	dfs(grid, row, col + 1);
	dfs(grid, row, col - 1);
 
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
 
	int cnt = 0;
 
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < m ; j++)
		{
			if (v[i][j] == '.')
			{
				cnt++;
				dfs(v, i, j);
 
			}
		}
	}
 
 
	cout << cnt << endl;
 
	return 0 ;
}
 