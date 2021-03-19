#include <bits/stdc++.h>
using namespace std;
//d[i][j]= 끝자리가 j인 i자리의 숫자
long long d[101][10];
const long long MOD = 1000000000;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i < 10; i++) d[1][i] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > 0) {
				d[i][j] += d[i - 1][j - 1];
				d[i][j] %= MOD;
			}
			if (j < 9) {
				d[i][j] += d[i - 1][j + 1];
				d[i][j] %= MOD;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
		ans %= MOD;
	}
	cout << ans;
}