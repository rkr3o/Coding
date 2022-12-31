#include<bits/stdc++.h>
using namespace std ;
#define ll long long int

// using memoisation method
int dp[10000]; int dp2[10000];
int solve(int n )
{
	if (n <= 1)
	{
		return n ;
	}

	memset(dp, -1, sizeof(dp));

	if (dp[n] != -1)
	{
		return dp[n];
	}
	else dp[n] = solve(n - 1) + solve(n - 2);

	return dp[n];
}

// using tabulation method

int solve2(int n)
{
	if (n < 2)return n;
	memset(dp2, -1, sizeof(dp));

	if (dp2[n] != -1)return dp2[n];

	dp2[0] = 0 , dp2[1] = 1;

	for (int i = 2 ; i <= n; i++ )
	{
		dp2[i] = dp2[i - 1] + dp2[i - 2];
	}

	return dp2[n];

}
int main()
{
	int n ;
	cin >> n ;

	cout << solve(n);
	cout << endl;
	cout << solve2(n);
	return 0 ;
}