#include <bits/stdc++.h>

using namespace std;

int N, L, answer;
vector<vector <int>> m;

void checking_row(int line_num) {
	vector<bool> length_check;
	length_check.assign(N, false);

	int floor, length_cnt;

	for (int i = 0; i < N - 1; i++) {
		floor = m[line_num][i] - m[line_num][i + 1];
		length_cnt = 0;

		if (abs(floor) > 1) return;

		if (floor == -1) {
			for (int j = i; i - j < L; j--) {
				if (j < 0) break;

				if (m[line_num][i] == m[line_num][j]) {
					length_cnt++;

					if (length_check[j]) return;

					length_check[j] = true;
				}
			}

			if (length_cnt < L) return;
		}
		else if (floor == 1) {
			for (int j = i + 1; j - i - 1 < L; j++) {
				if (j >= N) break;

				if (m[line_num][i + 1] == m[line_num][j]) {
					length_cnt++;

					if (length_check[j]) return;

					length_check[j] = true;
				}
			}

			if (length_cnt < L) return;
		}
	}

	answer += 1;
}

void checking_col(int line_num) {
	vector<bool> length_check;
	length_check.assign(N, false);

	int floor, length_cnt;

	for (int i = 0; i < N - 1; i++) {
		floor = m[i][line_num] - m[i + 1][line_num];
		length_cnt = 0;

		if (abs(floor) > 1) return;

		if (floor == -1) {
			for (int j = i; i - j < L; j--) {
				if (j < 0) break;

				if (m[i][line_num] == m[j][line_num]) {
					length_cnt++;

					if (length_check[j]) return;

					length_check[j] = true;
				}
			}

			if (length_cnt < L) return;
		}
		else if (floor == 1) {
			for (int j = i + 1; j - i - 1 < L; j++) {
				if (j >= N) break;

				if (m[i + 1][line_num] == m[j][line_num]) {
					length_cnt++;

					if (length_check[j]) return;

					length_check[j] = true;
				}
			}

			if (length_cnt < L) return;
		}
	}

	answer += 1;
}

int main() {
	cin>>N>>L;

	m.resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a = 0;
			scanf("%d", &a);
			m[i].push_back(a);
		}
	}

	for (int i = 0; i < N; i++) {
		checking_row(i);
		checking_col(i);
	}

	cout<<answer;	
}
