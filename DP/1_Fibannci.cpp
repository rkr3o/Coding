#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
// recusrive approach
int recusriveFib(int n )
{
	if (n <= 2)return n;
	else
		return recusriveFib(n - 1) + recusriveFib(n - 2);
}
int main()
{
	int n ;
	cin >> n ;

	// iterative approach
	int f1 = 0 , f2 = 1;

	for (int i = 0; i <= n; ++i)
	{
		int ans ;
		cout << f2 << " ";
		ans = f1 + f2;
		f1 = f2;
		f2 = ans;

	}
	cout << endl;
	cout << recusriveFib(n);

}