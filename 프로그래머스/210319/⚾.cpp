#include <bits/stdc++.h>
using namespace std;
int per[9],a[51][9],ru[4];
//해시+완전탐색
// 1~ 3루 주자까지 , 4루주자는 따로, 5~9루주자 해쉬로 돌리면서 탐색

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		per[i] = i + 1;
	}
	do {
		int ining = 0,tans=0,out_count=0,run_number=0;
		while (true) {
			if (a[ining][per[run_number]] == 0) {
				out_count++;
				if (out_count == 3) {
					out_count = 0;
					for (int i = 1; i < 4; i++)ru[i] = 0;
					ining++;
					if (ining == n)break;
				}
			}
			else {
				ru[0] = 1;
				for (int i = 3; i >= 0; i--) {
					if (ru[i]) {
						if (i + a[ining][per[run_number]] >= 4) {
							ru[i] = 0;
							tans++;
						}
						else {
							ru[i + a[ining][per[run_number]]] = 1;
							ru[i] = 0;
						}
					}
				}
			}
			run_number++;
			if (run_number == 3)run_number = 8;
			else if (run_number == 9)run_number = 3;
			else if (run_number == 8)run_number = 0;
		}
		ans = max(ans, tans);
	} while (next_permutation(per, per + 8));
	cout << ans << '\n';
}