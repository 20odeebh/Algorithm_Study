#include<iostream>
#define max_n 100000
#define M 1000000009
using namespace std;

long long dp[max_n + 1][4];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= max_n; ++i)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % M;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % M;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % M;
	}

	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		cout << (dp[num][1] + dp[num][2] + dp[num][3]) % M << '\n';
	}
	return 0;
}