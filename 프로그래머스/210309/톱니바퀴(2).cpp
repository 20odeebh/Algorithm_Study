#include <bits/stdc++.h>
using namespace std;
//톱니바퀴 12시방향의 인덱스와, 변화 배열을 두어
//인덱스를 이용해서 각 톱니바퀴별로 극이 같은지 검사
//같으면 양쪽으로 뻗어나가면서 변화배열을 갱신해준다.
//톱니바퀴 1과의 차이점은 갯수를 4에서 total 까지 늘려준 것
string s[1001];
int state[1001] = { 0, }, change[1001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int total;
	cin >> total;
	for (int i = 0; i < total; i++)cin >> s[i];
	int T;
	cin >> T;
	while (T--) {
		int n, t;
		cin >> n >> t;
		n--;
		for (int i = 0; i < total; i++)change[i] = 0;
		change[n] = t;
		int l = n - 1, r = n + 1;
		while (l >= 0) {
			int l_right = state[l] + 2, r_left = state[l + 1] - 2;
			if (l_right >= 8)l_right -= 8;
			if (r_left < 0)r_left += 8;
			if (s[l][l_right] == s[l + 1][r_left]) {
				break;
			}
			else {
				change[l] = -change[l + 1];
				l--;
			}
		}
		while (r < total) {
			int l_right = state[r - 1] + 2, r_left = state[r] - 2;
			if (l_right >= 8)l_right -= 8;
			if (r_left < 0)r_left += 8;
			if (s[r - 1][l_right] == s[r][r_left]) {
				break;
			}
			else {
				change[r] = -change[r - 1];
				r++;
			}
		}
		for (int i = 0; i < total; i++) {
			state[i] -= change[i];
			if (state[i] < 0)state[i] += 8;
			if (state[i] >= 8)state[i] -= 8;

		}
	}
	int ans = 0;
	for (int i = 0; i < total; i++) {
		if (s[i][state[i]] == '1')ans++;
	}
	cout << ans;
}