#include<iostream>
#define max_n 1000
using namespace std;

int dp[max_n + 1];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= 1000; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[n] << '\n';

	return 0;
}