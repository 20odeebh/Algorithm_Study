#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int field[100][100][100];
int visit[100][100][100];
int N, H, M;
int tomato = 0;
struct Node {
	int dep, row, col;
};
queue<Node> q;
Node dir[] = {
	{ 0, 1, 0 },
	{ 0, 0, 1 },
	{ 0, -1, 0 },
	{ 0, 0, -1 },
	{ 1, 0, 0 },
	{ -1, 0, 0 }
};
int bfs()
{
	int r, c, d;
	int nr, nc, nd, answer = 0;
	int cnt = q.size();
	if (cnt == tomato)
		return 0;
	while (!q.empty()) {
		r = q.front().row;
		c = q.front().col;
		d = q.front().dep;
		q.pop();
		for (int i = 0; i < 6; i++) {
			nr = r + dir[i].row;
			nc = c + dir[i].col;
			nd = d + dir[i].dep;
			if (nr < 0 || nc < 0 || nd < 0 ||
				nr >= N || nc >= M || nd >= H)
				continue;
			if (field[nd][nr][nc] == 0 && visit[nd][nr][nc] == 0) {
				visit[nd][nr][nc] = visit[d][r][c] + 1;
				q.push({ nd, nr, nc });
				answer = max(answer, visit[nd][nr][nc]);
				cnt++;
			}
		}
	}

	if (cnt != tomato)
		return -1;
	else
		return answer - 1;
}
int main()
{
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> field[h][n][m];
				if (field[h][n][m] == 1) {
					q.push({ h, n, m });
					visit[h][n][m] = 1;
					tomato++;
				}
				else if (field[h][n][m] == 0)
					tomato++;
			}
		}
	}
	printf("%d\n", bfs());
	return 0;
}