#include <bits/stdc++.h>
using namespace std;
int d[1001];
const int mod = 10007;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= mod;
	}
	cout << d[n];
}