#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int b[101][101];
bool check[101];
//작년보다 못짠소스
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l;
	cin >> n >> l;
	int n2 = n - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	int ans = 0;
	//행작업
	for (int i = 0; i < n; i++) {
		int start = 0;
		bool flag = true;
		for (int j = 0; j < n; j++)check[j] = false;
		while (start < n2) {
			if (abs(a[i][start] - a[i][start + 1]) > 1) {
				flag = false;
				break;
			}
			if (a[i][start] > a[i][start + 1]) {
				int start2 = start + 1;
				int cnt = 0, now = a[i][start2];
				while (start2 < n) {
					if (now == a[i][start2]) {
						start2++;
						cnt++;
						if (cnt == l)break;
					}
					else {
						break;
					}
				}
				if (cnt == l) {
					for (int j = start + 1; j < start2; j++) {
						check[j] = true;
					}
					start = start2-1;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (a[i][start] == a[i][start + 1]) {
				start++;
			}
			else {
				int start2 = start;
				int cnt = 0,now=a[i][start2];
				while (start2 >= 0) {
					if (check[start2])break;
					if (now == a[i][start2]) {
						start2--;
						cnt++;
						if (cnt == l)break;
					}
					else {
						break;
					}
				}
				if (cnt == l) {
					for (int j = start; j > start2; j--) {
						check[j] = true;
					}
					start++;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			ans++;
		}
	}
	//열작업
	for (int i = 0; i < n; i++) {
		int start = 0;
		bool flag = true;
		for (int j = 0; j < n; j++)check[j] = false;
		while (start < n2) {
			if (abs(a[start][i] - a[start+1][i]) > 1) {
				flag = false;
				break;
			}
			if (a[start][i] > a[start+1][i]) {
				int start2 = start + 1;
				int cnt = 0, now = a[start2][i];
				while (start2 < n) {
					if (now == a[start2][i]) {
						start2++;
						cnt++;
						if (cnt == l)break;
					}
					else {
						break;
					}
				}
				if (cnt == l) {
					for (int j = start + 1; j < start2; j++) {
						check[j] = true;
					}
					start = start2 - 1;
				}
				else {
					flag = false;
					break;
				}
			}
			else if (a[start][i] == a[start+1][i]) {
				start++;
			}
			else {
				int start2 = start;
				int cnt = 0, now = a[start2][i];
				while (start2 >= 0) {
					if (check[start2])break;
					if (now == a[start2][i]) {
						start2--;
						cnt++;
						if (cnt == l)break;
					}
					else {
						break;
					}
				}
				if (cnt == l) {
					for (int j = start; j > start2; j--) {
						check[j] = true;
					}
					start++;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			ans++;
		}
	}
	cout << ans << '\n';
}