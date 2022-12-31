// memoisation 
#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
const int mod = 1e9 + 7;
ll dp[1000000 + 1];
vector<int>v;
int solve(int idx , int n )
{
	if (idx > n - 1)
	{
		return  mod ;
	}

	if (idx == n - 1)
	{
		return 0 ;
	}

	if (dp[idx] != -1)
	{
		return dp[idx];
	}

	int jump1 = abs(v[idx + 1] - v[idx] ) + solve(idx + 1 , n);

	int jump2 = abs(v[idx + 2] - v[idx] ) + solve(idx + 2 , n );


	return dp[idx] = min(jump1, jump2);

}
int main()
{
	int n ;
	cin >> n ;
	v = vector<int>(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	memset(dp , -1 , sizeof(dp));
	cout << solve(0, n);
	return 0 ;
}