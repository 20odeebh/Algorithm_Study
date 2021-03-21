#include <iostream>
#include <algorithm>

#define max_n 100000

using namespace std;

int map[2][max_n+1];
int dp[2][max_n+1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t;
	int n;

	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> map[0][i];

		for (int i = 0; i < n; ++i)
			cin >> map[1][i];

		dp[0][0] = map[0][0];
		dp[1][0] = map[1][0];
		dp[0][1] = map[0][1] + dp[1][0];
		dp[1][1] = map[1][1] + dp[0][0];

		for (int i = 2; i < n; ++i)
		{
			dp[0][i] = map[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = map[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}


		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';

	}

}