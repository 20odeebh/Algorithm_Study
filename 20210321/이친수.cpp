#include<iostream>
#define max_n 90
using namespace std;
long long dp[max_n + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 5;

	for (int i = 6; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << '\n';

	return 0;
}