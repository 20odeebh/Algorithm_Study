#include <bits/stdc++.h>
using namespace std;
//d[i][j] = 끝자리가 j 인 i자리 수의 경우의 수
int d[1001][10];
const int MOD = 10007;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)d[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
		ans %= MOD;
	}
	cout << ans;
}