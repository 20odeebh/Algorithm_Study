#include<iostream>
#include <algorithm>
#define MOD 10007;

using namespace std;
int n;
// i로 끝나는 j길이의 오르막 수
long long dp[10][1001] = { 0, };

int main()
{
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;
	// 0 1 2 3 4 5 6 7 8 9 
	

	// 01 (1)
	// 02 12
	// 03 13 23 
	// 04 
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				// j로 끝나는 i길이는 
				// i-1 길이에서 j보다 작은 값으로 끝나는 것에 +1만 하면 된다.
				dp[j][i] += dp[k][i - 1] % MOD;
			}
		}
	}

	long long tmp = 0;
	for (int i = 0; i < 10; i++)
		tmp += dp[i][n] % MOD;
	cout << tmp%MOD;

}