#include <bits/stdc++.h>

using namespace std;
int t, a[1004][8], k,ans;
void rotate(int n, int d) {
	int tp[8] = { 0 };
	if (d == 1) {
		for (int i = 0; i < 8; i++) {
			tp[(i+1)%8] = a[n][i];
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			tp[i] = a[n][(i + 1) % 8];
		}
	}
	for (int i = 0; i < 8; i++) {
		a[n][i] = tp[i];
	}
}
void solve() {
	while (k--)
	{
		int n = 0, d = 0, dir[1004] = { 0 };
		cin >> n >> d;
		dir[--n] = d;
		for (int i = n; i < t - 1; i++) {
			if (a[i][2] != a[i + 1][6]) dir[i + 1] = -dir[i];
		}
		for (int i = n; i >0; i--) {
			if (a[i][6] != a[i - 1][2]) dir[i - 1] = -dir[i];
		}
		for (int i = 0; i < t; i++) {
			if (dir[i]) rotate(i, dir[i]);
		}

	}
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	cin >> k;
	solve();
	for (int i = 0; i < t; i++) {
		if (a[i][0]) ans++;
	}
	cout << ans;
}