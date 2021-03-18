#include <bits/stdc++.h>
using namespace std;
int d[1001], a[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
		for (int j = 1; j < i; j++) {
			d[i] = min(d[i], a[j] + d[i - j]);
		}
	}
	cout << d[n] << '\n';
}