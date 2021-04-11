#include <iostream>

using namespace std;

int n, m, k;
int board[20][20][3];

struct SHARK {
	int y, x, d;
	int p[4][4];
};
SHARK shark[400];

int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

int solve() {
	int time = 0;
	int shark_kill = 0;
	while (time <= 1000) {
		time++;
		int new_board[20][20][3] = { 0 };

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				new_board[y][x][0] = board[y][x][0];
				new_board[y][x][2] = board[y][x][2];
				if (new_board[y][x][2] > 0) {
					--new_board[y][x][2];
				}
				if (new_board[y][x][2] > 0) {
					
					new_board[y][x][1] = board[y][x][1];
					
				}
			}
		}
		
		for (int i = 0; i < m; i++) {
			int cy = shark[i].y;
			int cx = shark[i].x;
			int cd = shark[i].d;
			if (cy == -1)continue;
			bool is_move = false;
			for (int d = 0; d < 4; d++) {
				int nd = shark[i].p[cd][d];
				int ny = cy + dy[nd];
				int nx = cx + dx[nd];
				
				if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx][2] != 0)continue;
				new_board[cy][cx][0] = 0;
				is_move = true;
				if (new_board[ny][nx][0] == 0) {
					
					new_board[ny][nx][0] = i + 1;
					new_board[ny][nx][1] = i + 1;
					new_board[ny][nx][2] = k;
					shark[i].y = ny;
					shark[i].x = nx;
					shark[i].d = nd;
				}
				else {
					shark[i].y = -1;
					shark_kill++;
				}
				break;
			}
			if (is_move == false) {
				for (int d = 0; d < 4; d++) {
					int nd = shark[i].p[cd][d];
					int ny = cy + dy[nd];
					int nx = cx + dx[nd];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n )continue;
					if (board[ny][nx][2] != 0 && board[ny][nx][1] != i + 1)continue;
					new_board[cy][cx][0] = 0;
					if (new_board[ny][nx][0] == 0) {
						new_board[ny][nx][0] = i + 1;
						new_board[ny][nx][1] = i + 1;
						new_board[ny][nx][2] = k;
						shark[i].y = ny;
						shark[i].x = nx;
						shark[i].d = nd;
					}
					else {
						shark[i].y = -1;
						shark_kill++;
					}
					break;
				}
			}
		}
    
		if (shark_kill == m - 1) break;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				board[y][x][0] = new_board[y][x][0];
				board[y][x][1] = new_board[y][x][1];
				board[y][x][2] = new_board[y][x][2];
			}
		}
	}
	if (time <= 1000)return time;
	else return -1;
}

int main() {
	cin >> n >> m >> k;

	int num = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> num;
			if (num != 0) {
				int sharknum = num - 1;
				board[y][x][0] = num;
				board[y][x][1] = num;
				board[y][x][2] = k;
				shark[sharknum].y = y;
				shark[sharknum].x = x;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> shark[i].d;
		--shark[i].d;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> shark[i].p[j][0] >> shark[i].p[j][1] >> shark[i].p[j][2] >> shark[i].p[j][3];
			--shark[i].p[j][0],--shark[i].p[j][1],--shark[i].p[j][2],--shark[i].p[j][3];
		}
	}

	cout << solve();
}
