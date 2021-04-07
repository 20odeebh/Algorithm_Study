#include <iostream>

using namespace std;

int n, ret;
int s[20][20], pick[20];
int a[10], b[10];

void update() {
	int a_cnt = 0, b_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (pick[i]) {
			a[a_cnt++] = i;
		}
		else {
			b[b_cnt++] = i;
		}
	}
	int a_sum = 0, b_sum = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = i + 1; j < n / 2; j++) {
			a_sum += s[a[i]][a[j]] + s[a[j]][a[i]];
			b_sum += s[b[i]][b[j]] + s[b[j]][b[i]];
		}
	}
	if (ret > abs(a_sum - b_sum))ret = abs(a_sum - b_sum);
}

void dfs(int cur, int cnt) {
	if (cnt == n / 2) {
		update();
		return;
	}
	for (int i = cur; i < n; i++) {
		pick[i] = 1;
		dfs(i + 1, cnt + 1);
		pick[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	ret = 0x7fffffff;
	dfs(0, 0);
	cout << ret;
}
