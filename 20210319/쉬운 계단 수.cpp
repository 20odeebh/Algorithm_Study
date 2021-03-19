#include<iostream>
#define m 1000000000
#define max_n 100
using namespace std;

int n;
long long dp[max_n + 1][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 9; ++i)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; ++j)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % m;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; ++i)
	{
		ans += dp[n][i];
	}
	cout << ans % m << '\n';

	return 0;
}