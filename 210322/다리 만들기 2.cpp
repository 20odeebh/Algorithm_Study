#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int Height, Width;
int arr[11][11];
int visit[11][11];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
struct bridge {
	int from_row, from_col;
	int to_row, to_col;
	int dist;
};
struct island {
	int r, c;
	int num;
};
vector<bridge> bridges;
int parents[101];

bool cmp(bridge& b1, bridge& b2)
{
	return b1.dist < b2.dist;
}
bool IsRange(int nr, int nc)
{
	if (nr >= 0 && nc >= 0 && nr < Height && nc < Width)
		return true;
	return false;
}
vector<bridge> make_bridge(int row, int col)
{
	bridge b;
	vector<bridge> result;
	int nr, nc, dist = 0;
	for (int dir = 0; dir < 4; dir++) {
		dist = 1;
		while (1) {
			nr = row + dirRow[dir] * dist;
			nc = col + dirCol[dir] * dist;
			if (!IsRange(nr, nc))
				break;
			if (arr[nr][nc] == 1) {
				if (dist > 2) {
					b = { row, col, nr, nc, dist - 1 };
					result.push_back(b);
				}
				break;
			}
			dist++;
		}
	}
	return result;
}
bool find_island(int row, int col, int number)
{
	island la = { row, col, number };
	queue<island> q;
	q.push(la);
	visit[row][col] = number;
	int r, c, nr, nc, n;
	while (!q.empty()) {
		r = q.front().r;
		c = q.front().c;
		n = q.front().num;
		q.pop();
		auto brs = make_bridge(r, c);
		for (const auto& b : brs)
			bridges.push_back(b);

		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= Height || nc >= Width)
				continue;
			if (arr[nr][nc] == 1 && visit[nr][nc] == 0) {
				visit[nr][nc] = n;
				la = { nr, nc, n };
				q.push(la);
			}
		}
	}
	return true;
}
int get_parent(int x)
{
	if (parents[x] == x)
		return x;
	return parents[x] = get_parent(parents[x]);
}
void union_parent(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if (a < b)
		parents[b] = a;
	else
		parents[a] = b;
}
int find(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if (a == b)
		return 1;
	else
		return 0;
}
int main()
{
	cin >> Height >> Width;
	for (int r = 0; r < Height; r++)
		for (int c = 0; c < Width; c++)
			cin >> arr[r][c];
	for (int i = 0; i < 101; i++)
		parents[i] = i;
	int number = 1;
	for (int r = 0; r < Height; r++) {
		for (int c = 0; c < Width; c++) {
			if (arr[r][c] == 1 && visit[r][c] == 0) {
				find_island(r, c, number++);
			}
		}
	}
	sort(bridges.begin(), bridges.end(), cmp);
	int answer = 0;
	for (int i = 0; i < bridges.size(); i++) {
		auto &b = bridges[i];
		int fr, fc, tr, tc;
		fr = b.from_row, fc = b.from_col;
		tr = b.to_row, tc = b.to_col;
		if (!find(visit[fr][fc], visit[tr][tc])) {
			union_parent(visit[fr][fc], visit[tr][tc]);
			answer += b.dist;
		}
	}
	int island_number = get_parent(1);
	for (int i = 2; i < number; i++) {
		if (island_number != get_parent(i)) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", answer);
	return 0;
}