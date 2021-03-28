#include <bits/stdc++.h>
using namespace std;
//그리디로 하려했다가 안될거 같아서 정답참조 해서 백트래킹으로 해결
//백트래킹도 시간초과가 긴가민가 했지만 됐다.
int a[10][10];
pair<int, int> one[101];
int paper_cnt[6] = { 0,5,5,5,5,5 };
int cnt1=0,idx=0,ans=-1;
bool check(int x,int y,int n) {
	int x2 = x + n, y2 = y + n;
	if (x2 > 10 || y2 > 10)return false;
	for (int i = x; i < x2; i++) {
		for (int j = y; j < y2; j++) {
			if (a[i][j] == 0)return false;
		}
	}
	return true;
}

void swap(int x, int y, int n, int num) {
	int x2 = x + n, y2 = y + n;
	for (int i = x; i < x2; i++) {
		for (int j = y; j < y2; j++) {
			a[i][j] = num;
		}
	}
}
void dfs(int num,int cnt) {
	if (num >= idx) {
		if (ans == -1) {
			ans = cnt;
		}
		else {
			ans = min(ans, cnt);
		}
		return;
	}
	int x = one[num].first, y = one[num].second;
	if (a[x][y] == 0) {
		dfs(num + 1, cnt);
	}
	else {
		for (int i = 1; i <= 5; i++) {
			if (paper_cnt[i] == 0)continue;
			if (check(x, y, i)) {
				swap(x, y, i, 0);
				paper_cnt[i]--;
				dfs(num + 1, cnt + 1);
				swap(x, y, i, 1);
				paper_cnt[i]++;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
			if (a[i][j]) {
				cnt1++;
				one[idx].first = i;
				one[idx].second = j;
				idx++;
			}
		}
	}
	dfs(0,0);
	cout << ans << '\n';
}