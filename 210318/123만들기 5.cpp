#include<iostream>
#include <algorithm>
#define MOD 1000000009

using namespace std;
int n;
long long dp[100001][4] = { 0, };
int main()
{
	cin >> n;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	// dp 에서 추가적인 정보가 필요함 -> 2차원 배열로 정보 추가하기
	for (int i = 4; i < 100001; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		cout << (dp[num][1] + dp[num][2] + dp[num][3]) % MOD << '\n';
	}

}