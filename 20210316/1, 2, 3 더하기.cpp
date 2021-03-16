#include<iostream>
#define max_n 15
using namespace std;
int n;
int dp[max_n + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1; // 1
	dp[2] = 2; // 11, 2
	dp[3] = 4;//111,12, 21, 3
	dp[4] = 7;

	for (int i = 5; i <= 11; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;

		cout << dp[num] << '\n';
	}

	return 0;
}