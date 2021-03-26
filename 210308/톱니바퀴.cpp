#include <bits/stdc++.h>

using namespace std;

int k, ans,a[4][8],r[4];

void setRt(int idx, int rt) {
	memset(r, 0, sizeof(r));
	r[idx] = rt;
	for (int i = idx; i < 3; i++) {
		if (a[i][2] != a[i + 1][6]) r[i + 1] = -r[i];
	}
	for (int i = idx; i > 0; i--) {
		if (a[i][6] != a[i - 1][2]) r[i - 1] = -r[i];
	}
}

void rotate() {
	for (int i = 0; i < 4; i++) {
		int t[8] = { 0 };
		if (r[i] == 1) {
			for (int j = 1; j <= 7; j++) {
				t[j] = a[i][j - 1];
			}
			t[0] = a[i][7];
			for (int j = 0; j <= 7; j++) {
				a[i][j] = t[j];
			}
		}
		if (r[i] == -1) {
			for (int j = 0; j <= 6; j++) {
				t[j] = a[i][j + 1];
			}
			t[7] = a[i][0];
			for (int j = 0; j <= 7; j++) {
				a[i][j] = t[j];
			}
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	cin >> k;
	while (k--) {
		int idx = 0, rt = 0;
		cin >> idx >> rt;
		setRt(idx - 1, rt);
		rotate();
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i][0] == 1)sum += (1 << i);
	}
	cout << sum;
}