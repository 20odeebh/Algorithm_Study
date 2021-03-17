#include<iostream>
#define max_n 1000000
using namespace std;
long long dp[max_n + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	for (int i = 4; i <= max_n; ++i)
	{
		long long temp;
		temp = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		dp[i] = temp;
	}

	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		cout << dp[num] << '\n';
	}

	return 0;
}