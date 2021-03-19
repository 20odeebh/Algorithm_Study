#include<iostream>
#define m 10007
#define max_n 1000
using namespace std;

int n;
long long dp[max_n + 1][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i <= 9; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = j; k <= 9; ++k)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % m;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; ++i)
	{
		ans = (ans + dp[n][i]) % m;
	}
	cout << ans << '\n';
	return 0;
}