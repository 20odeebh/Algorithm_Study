#include<iostream>
#include <algorithm>

using namespace std;
int n;
int dp[1001];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		dp[i] = num;
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}
	cout << dp[n];
}