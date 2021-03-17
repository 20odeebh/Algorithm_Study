#include<iostream>

long long MOD = 1000000009;

using namespace std;
int n;
long long dp[1000001];

int main()
{
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 1000001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		cout << dp[tmp] % MOD << '\n';
	}
}