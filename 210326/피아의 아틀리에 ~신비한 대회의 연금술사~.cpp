#include <iostream>
#include <cstring>
using namespace std;

int N, Answer;
bool Check[10];
pair<int, char> Pot[5][5];
pair<int, char> Materials[10][4][4][4];
void initPot() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			Pot[i][j] = { 0, 'W' };
}

int calc() {
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (Pot[i][j].second == 'W') continue;
			int power = Pot[i][j].first;
			switch (Pot[i][j].second) {
			case 'R': ret += (7 * power);
				break;
			case 'B': ret += (5 * power);
				break;
			case 'G': ret += (3 * power);
				break;
			case 'Y': ret += (2 * power);
				break;
			}
		}
	}
	return ret;
}

void put(int n, int d, int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Pot[x + i][y + j].first += Materials[n][d][i][j].first;
			if (Pot[x + i][y + j].first > 9) Pot[x + i][y + j].first = 9;
			if (Pot[x + i][y + j].first < 0) Pot[x + i][y + j].first = 0;
			if (Materials[n][d][i][j].second == 'W') continue;
			Pot[x + i][y + j].second = Materials[n][d][i][j].second;
		}
	}
}

void solve(int cnt = 0) {
	if (cnt == 3) {
		if (Answer < calc())
			Answer = calc();
		return;
	}

	pair<int, char> tmp[5][5];
	memcpy(tmp, Pot, sizeof(Pot));
	for (int i = 0; i < N; i++) {
		if (!Check[i]) {
			Check[i] = true;
			for (int d = 0; d < 4; d++) {
				for (int x = 0; x < 2; x++) {
					for (int y = 0; y < 2; y++) {
						put(i, d, x, y);
						solve(cnt + 1);
						memcpy(Pot, tmp, sizeof(tmp));
					}
				}
			}
			Check[i] = false;
		}
	}
}

void addRotate(int n) {
	for (int d = 0; d < 3; d++) {
		pair<int, char> tmp[4][4];
		auto v = Materials[n];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				tmp[j][3 - i] = v[d][i][j];
		memcpy(v[d + 1], tmp, sizeof(tmp));
	}
}

int main() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> Materials[n][0][i][j].first;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> Materials[n][0][i][j].second;
		addRotate(n);
	}
	solve();
	cout << Answer << endl;
	return 0;
}
