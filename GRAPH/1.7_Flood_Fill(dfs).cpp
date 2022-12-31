#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int  mod = 1e9 + 7 ;

void dfs(vector<vector<int>>&image , int row , int col , int val , int newColor  )
{
	int n = image.size();
	int m = image[0].size();
	if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] == newColor || image[row][col] != val)
	{
		return;
	}
	image[row][col] = newColor ;
	dfs(image, row - 1, col, val, newColor);
	dfs(image, row + 1, col, val, newColor);
	dfs(image, row, col - 1, val, newColor);
	dfs(image, row, col + 1, val, newColor);

}

int main()
{
	int n , m ;
	cin >> n >> m ;

	vector<vector<int>>v(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j] ;
		}
	}

	int sr , sc , color ;
	cin >> sr >> sc >> color ;

	int initalColor = v[sr][sc];

	dfs(v , sr , sc , initalColor , color);

	for (int i = 0 ; i < v.size(); i++)
	{
		for (int j = 0 ; j < v[0].size() ; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}


	return 0 ;
}