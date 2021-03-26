#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool flag = false;
	while (1) {
		vector<vector<bool>> check(m, vector<bool>(n, false));
		flag = false;

		for (int i = 0; i < m - 1; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				char c = board[i][j];
				if (c == '*')		
					continue;
				if (board[i + 1][j + 1] == c && board[i][j + 1] == c && board[i + 1][j] == c ) {
					check[i][j] = true;
					check[i][j + 1] = true;
					check[i + 1][j] = true;
					check[i + 1][j + 1] = true;
					flag = true;
				}
			}
		}

		if (!flag)
			break;


		for (int i = 0; i < m; i++) {	
			for (int j = 0; j < n; j++) {
				if (check[i][j]) {
					for (int k = i - 1; k >= 0; k--) {
						board[k + 1][j] = board[k][j];
						board[k][j] = '*';
					}
					++answer;
				}
			}
		}
	}

	return answer;
}