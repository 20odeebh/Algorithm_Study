#include <iostream>
using namespace std;
int N;
long long dp[2][91];
//dp[0][N] = dp[0][N - 1] + dp[1][N - 1]
//dp[1][N] = dp[0][N - 1]
int main()
{
	cin >> N;
	dp[1][1] = 1, dp[0][1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	printf("%lld\n", dp[0][N] + dp[1][N]);
	return 0;
}