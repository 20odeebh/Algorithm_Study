#include<iostream>
#include<algorithm>
#define max_n 1000
using namespace std;

int p[max_n + 1];
int dp[max_n + 1];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	dp[1] = p[1];
	dp[2] = max(p[1] * 2, p[2]);
	for (int i = 3; i <= n; ++i) dp[i] = dp[i];

	for (int i = 3; i <= n; ++i)
	{
		for (int k = 1; k <= i; ++k)
		{
			dp[i] = max(dp[i], dp[i - k] + p[k]);
		}
	}

	cout << dp[n] << '\n';
	return 0;

}