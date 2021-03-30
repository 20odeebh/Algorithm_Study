// 뱀

#include <stdio.h>
#include <string.h>
#include <deque>
#include <set>

using namespace std;

int n, k, l;
bool arr[101][101];
char command[10001];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
set<pair<int, int>> s;
deque<pair<int, int>> dq;

int main() {
	scanf("%d", &n);
	scanf(" %d", &k);
	int y, x, d;
	for (int i = 0; i < k; i++) {
		scanf(" %d %d", &y, &x);
		s.insert(make_pair(y, x));
	}
	scanf(" %d", &l);
	int t;
	char ch;
	for (int i = 0; i < l; i++) {
		scanf(" %d %c", &t, &ch);
		command[t] = ch;
	}

	dq.push_back(make_pair(1, 1));
	arr[1][1] = true;
	d = 0;
	t = 0;
	while (true) {
		t++;
		y = dq.back().first;
		x = dq.back().second;
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny <= 0 || ny > n || nx <= 0 || nx > n || arr[ny][nx]) break;
		if (s.find(make_pair(ny, nx)) != s.end()) {
			s.erase(make_pair(ny, nx));
			dq.push_back(make_pair(ny, nx));
			arr[ny][nx] = true;
		}
		else {
			dq.push_back(make_pair(ny, nx));
			arr[ny][nx] = true;
			arr[dq.front().first][dq.front().second] = false;
			dq.pop_front();
		}

		if (command[t] == 'L') d = (d + 3) % 4;
		else if (command[t] == 'D') d = (d + 1) % 4;
	}
	printf("%d\n", t);
	return 0;
}