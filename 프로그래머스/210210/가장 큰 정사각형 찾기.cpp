#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int d[1001][1001];
// 다이나믹 프로그래밍
int solution(vector<vector<int>> board)
{
	int answer = 0;
	int n = board.size(), m = board[0].size();
	for (int i = 0; i < n; i++) {
		if (board[i][0])d[i][0] = 1;
		else d[i][0] = 0;
		answer = max(answer, d[i][0]);
	}
	for (int i = 0; i < m; i++) {
		if (board[0][i])d[0][i] = 1;
		else d[0][i] = 0;
		answer = max(answer, d[0][i]);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (board[i][j]) {
				d[i][j] = min(d[i - 1][j], min(d[i - 1][j - 1], d[i][j - 1])) + 1;
				answer = max(answer, d[i][j]);
			}
		}
	}

	return answer * answer;
}