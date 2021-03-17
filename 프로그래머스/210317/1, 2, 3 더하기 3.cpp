#include <bits/stdc++.h>
using namespace std;
long long d[1000001];
const long long MOD = 1000000009;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		d[i] %= MOD;
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}