#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
vector<int>v;

int solve(int n , int idx)
{
	if (idx >= n)
		return 0 ;

	int pick = v[idx] + solve(n , idx + 2);
	int notpick = solve(n, idx + 1);

	return max(pick, notpick);
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

	cout << solve(n, 0);


	return 0 ;
}