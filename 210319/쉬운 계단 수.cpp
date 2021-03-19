#include<iostream>
#include <algorithm>
#define MOD 1000000000;

using namespace std;
int n;
// dp[i][j] : i로 끝나는 j 길이의 개수
long long dp[10][101];

int main()
{
	cin >> n;
	// 길이 1 -> 9개 (1 2 3 4 5 6 7 8 9)
	// 길이 2 -> (12 23 34 45 56 67 78 89 
	// (10 21 32 43 .. 87 98)
	// 길이 3 -> 이전에 i로 끝났으면 
	for (int i = 1; i < 10; i++)
		dp[i][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0)
				// 한단계 큰 것만 붙이면 됨
				dp[j][i] += dp[j-1][i-1] % MOD;
			if (j + 1 < 10)
				// 한단계 작은 것만 붙이면 됨
				dp[j][i] += dp[j+1][i-1] % MOD;
		}
	}

	long long tmp = 0;
	for (int j = 0; j < 10; j++) {
		tmp += dp[j][n] % MOD;
	}

	cout << tmp%MOD;

}