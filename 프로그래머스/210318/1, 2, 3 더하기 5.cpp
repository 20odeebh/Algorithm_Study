#include <bits/stdc++.h>
using namespace std;
long long d[100001][4];
const long long MOD = 1000000009;
//d[i][j]=  i라는 숫자를 더해서 만들때 끝자리가 j인 경우의 수
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;
	for (int i = 4; i < 100001; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				if (j == k)continue;
				d[i][j] += d[i - j][k];
				d[i][j] %= MOD;
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3]) % MOD << '\n';
	}
}