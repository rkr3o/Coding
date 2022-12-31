// you r climbing  a stairs from 1 to n  , each time  it tame 1 or 2 steps , how many
// distinct ways can you climb  at the stairs



#include<bits/stdc++.h>
using namespace std ;

// recursive approach : O(2^n) / O(n)
int solve(int n )
{
	if (n <= 1)
		return n;

	return solve(n - 1) + solve(n - 2);
}

// top down approach / memoisation : O(n) , O(n):recusrion + O(n):array : O(n);

int dp[50];

int dpMemo(int n)
{
	memset(dp, -1, sizeof(dp));

	if (n < 2)return n;

	if (dp[n] != -1)
	{
		return dp[n];
	}
	else  {
		dp[n] = dpMemo(n - 1) + dpMemo(n - 2);
	}

	return dp[n];
}

//bottom up approach / tabulation : O(n),O(n):array used

int dpTabu(int n)
{
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2 ; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}
// space optimisation

int dpSpaceOptimisation(int n)
{
	int a = 0 , b = 1 , next , prev;

	for (int i = 2 ; i <= n ; i++)
	{
		next = a + b;
		b = a ;
		a = next;
	}

	return  a ;
}
int main()
{
	int n ;
	cin  >> n ;

	cout << solve(n) << endl;
	cout << dpMemo(n) << endl;
	cout << dpTabu(n) << endl;
	cout << dpSpaceOptimisation(n) << endl;
}