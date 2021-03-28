#include <iostream>
#include <algorithm>
using namespace std;
int a[2][100001];
int d[2][100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, max1;
	cin >> t;
	while (t) {
		cin >> n;
		max1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> a[1][i];
		}
		d[0][0] = a[0][0];
		d[1][0] = a[1][0];
		d[0][1] = d[1][0] + a[0][1];
		d[1][1] = d[0][0] + a[1][1];
		for (int i = 2; i < n; i++) {
			d[0][i] = max(d[1][i - 1], d[1][i - 2]) + a[0][i];
			d[1][i] = max(d[0][i - 1], d[0][i - 2]) + a[1][i];
		}
		max1 = max(d[0][n - 1], d[1][n - 1]);
		cout << max1 << '\n';
		t--;
	}
}