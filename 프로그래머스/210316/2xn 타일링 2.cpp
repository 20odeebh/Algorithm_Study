#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;
int d[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + 2*d[i - 2];
		d[i] %= MOD;
	}
	cout << d[n] << '\n';
}