#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX_SIZE 25
typedef pair<int, pair<int, int>> P;
int dp[MAX_SIZE][MAX_SIZE][4];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
queue<P> q;
int N;
vector<vector<int>> m;
int nextCost(int d, int nd)
{
	int angle = 500 + 100, str = 100;
	switch (d) {
	case 0:
		if (nd % 2 == 1)
			return angle;
		else
			return str;
	case 1:
		if (nd % 2 == 0)
			return angle;
		else
			return str;
	case 2:
		if (nd % 2 == 1)
			return angle;
		else
			return str;
	case 3:
		if (nd % 2 == 0)
			return angle;
		else
			return str;
	}
}
void bfs(int row, int col)
{
	int r, c, d, nr, nc, nd;
	while (!q.empty()) {
		r = q.front().second.first;
		c = q.front().second.second;
		d = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			nd = i;
			if (abs(nd - i) == 2)
				continue;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (m[nr][nc] == 0) {
				int cost = nextCost(d, nd);
				if (dp[nr][nc][nd] == -1 || dp[r][c][d] + cost < dp[nr][nc][nd]) {
					dp[nr][nc][nd] = dp[r][c][d] + cost;
					q.push({ nd,{ nr, nc } });
				}
			}
		}
	}
}
void setting()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < 4; k++)
				dp[i][j][k] = -1;
}
int solution(vector<vector<int>> board) {
	int answer = 987654321;
	N = board.size();
	m = board;
	setting();
	for (int i = 0; i < 4; i++) {
		dp[0][0][i] = 0;
		q.push({ i,{ 0, 0 } });
	}
	bfs(0, 0);
	for (int i = 0; i < 4; i++) {
		if (dp[N - 1][N - 1][i] == -1)
			continue;
		answer = min(dp[N - 1][N - 1][i], answer);
	}
	return answer;
}