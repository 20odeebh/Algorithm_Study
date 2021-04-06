#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int dir[11];
int board[12][12];
int exitTurn = -1;
bool exitCond = false;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

pair<int, int> piece[10];
vector<int> cell[20][20];

bool check_next(int i) {
	int r = piece[i].first;
	int c = piece[i].second;

	if (dir[i] == 1) { if (c + 1 >= N || board[r][c + 1] == 2) return false; }
	else if (dir[i] == 2) { if (c - 1 < 0 || board[r][c - 1] == 2) return false; }
	else if (dir[i] == 3) { if (r - 1 < 0 || board[r - 1][c] == 2) return false; }
	else if (dir[i] == 4) { if (r + 1 >= N || board[r + 1][c] == 2) return false; }

	return true;
}

int flip_dir(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else if (d == 4) return 3;
	return 0;
}

void move_piece(int i) {
	int r = piece[i].first;
	int c = piece[i].second;

	if (dir[i] == 1) { if (c + 1 >= N || board[r][c + 1] == 2) return; }
	else if (dir[i] == 2) { if (c - 1 < 0 || board[r][c - 1] == 2) return; }
	else if (dir[i] == 3) { if (r - 1 < 0 || board[r - 1][c] == 2) return; }
	else if (dir[i] == 4) { if (r + 1 >= N || board[r + 1][c] == 2) return; }

	int pos = 0;
	for (int p = 0; p < cell[r][c].size(); p++) {
		if (cell[r][c].at(p) == i) {
			pos = p;
			break;
		}
	}
	int rr = r + dx[dir[i] - 1];
	int cc = c + dy[dir[i] - 1];
	vector<int> tmp;
	for (int p = pos; p < cell[r][c].size(); p++) {
		int pNum = cell[r][c].at(p);
		tmp.push_back(pNum);

		piece[pNum].first = rr;
		piece[pNum].second = cc;
	}

	if (board[rr][cc] == 1) reverse(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		cell[rr][cc].push_back(tmp.at(i));
	}

	if (cell[rr][cc].size() >= 4) exitCond = true;

	int siz = cell[r][c].size();
	for (int p = pos; p < siz; p++) cell[r][c].pop_back();
}

void run_turn() {
	for (int i = 0; i < K; i++) {
		if (exitCond) break;
		if (!check_next(i)) dir[i] = flip_dir(dir[i]);
		move_piece(i);
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> piece[i].first >> piece[i].second;
		piece[i].first--;
		piece[i].second--;
		cin >> dir[i];
		cell[piece[i].first][piece[i].second].push_back(i);
	}

	for (int i = 0; i < 1000; i++) {
		run_turn();

		if (exitCond) {
			exitTurn = i + 1;
			break;
		}
	}

	cout << exitTurn << endl;
	return 0;
}