#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M;
int arr[51][51];
bool visit_chicken[51][51];
queue<pair<int, int>> houses;
deque<pair<int, int>> chick;
vector<int> result;
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
bool IsRange(int row, int col)
{
	if (1 <= row && 1 <= col && row <= N && col <= N)
		return true;
	return false;
}
int GetDist(int r1, int c1, int r2, int c2)
{
	int sum = 0;
	sum = abs(r1 - r2) + abs(c1 - c2);
	return sum;
}
void sim()
{
	auto h = houses;
	int cr, cc, hr, hc, sum = 0;
	while (!h.empty()) {
		hr = h.front().first;
		hc = h.front().second;
		h.pop();
		int dist = 987654321;
		auto c = chick;
		while (!c.empty()) {
			cr = c.front().first;
			cc = c.front().second;
			c.pop_front();
			dist = min(dist, GetDist(hr, hc, cr, cc));
		}
		sum += dist;
	}
	result.push_back(sum);
}
void dfs(int row, int col, int toPick)
{
	if (toPick == 0) {
		sim();
		return;
	}
	int r = row, c = col;
	for (; r <= N; r++) {
		for (; c <= N; c++) {
			if (arr[r][c] == 2 && visit_chicken[r][c] == false) {
				chick.push_back({ r, c });
				visit_chicken[r][c] = true;
				dfs(r, c, toPick - 1);
				chick.pop_back();
				visit_chicken[r][c] = false;
			}
		}
		c = 1;
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				houses.push({ i, j });
		}
	}
	dfs(1, 1, M);
	sort(result.begin(), result.end());
	printf("%d\n", result[0]);
	return 0;
}