#include<iostream>
#include<algorithm>
#define max_n 10000000
using namespace std;
int n;
int dp[max_n + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		int temp = dp[i - 1] + 1;
		if (i % 2 == 0) temp = min(temp, dp[i / 2] + 1);
		if (i % 3 == 0) temp = min(temp, dp[i / 3] + 1);
		dp[i] = temp;
	}

	cout << dp[n];
	return 0;
}