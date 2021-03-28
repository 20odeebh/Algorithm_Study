#include <bits/stdc++.h>
using namespace std;
//구현
int nn, mm,n2,m2;
vector<string> v;
int c[31][31];
int changeBlock() {
	int cnt = 0;
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < mm; j++) {
			c[i][j] = 1;
		}
	}
	//2*2 같은캐릭터를 찾는 과정
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			int flag = 0;
			if (v[i][j] == '#')continue;
			for (int o = i; o <= i + 1; o++) {
				for (int p = j; p <= j + 1; p++) {
					if (v[i][j] != v[o][p]) {
						flag = 1;
						break;
					}
				}
			}
			for (int o = i; o <= i + 1; o++) {
				for (int p = j; p <= j + 1; p++) {
					c[o][p] *= flag;
				}
			}
		}
	}
	//한번에 같이 지워준다
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < mm; j++) {
			if (c[i][j] == 0) {
				v[i][j] = '#';
				cnt++;
			}
		}
	}
	//밑으로 내리는 작업
	for (int j = 0; j < mm; j++) {
		for (int i = nn - 2; i >= 0; i--) {
			if (v[i][j] == '#')continue;
			for (int k = nn - 1; k > i; k--) {
				if (v[k][j] == '#') {
					swap(v[k][j], v[i][j]);
				}
			}
		}
	}
	return cnt;
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	v = board;
	swap(n, m);
	nn = n; mm = m;
	n2 = n - 1; m2 = m - 1;
	while (true) {
		int cnt = changeBlock();
		if (cnt == 0)break;
		answer += cnt;
	}
	return answer;
}