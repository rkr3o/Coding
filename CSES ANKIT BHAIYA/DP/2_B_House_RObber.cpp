#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
vector<int>v;
int dp[10000 + 1];
int solve(int n , int idx)
{
	if (idx >= n)
		return 0 ;
	if (dp[idx] != -1)
	{
		return dp[idx];
	}
	int pick = v[idx] + solve(n , idx + 2);
	int notpick = solve(n, idx + 1);

	return dp[idx] = max(pick, notpick);
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
	cout << solve(n, 0);


	return 0 ;
}