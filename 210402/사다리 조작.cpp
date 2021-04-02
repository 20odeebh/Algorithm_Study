#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_H 31
#define MAX_W 11
#define INF 987654321
int N, M, H; //세로선, 가로선, 가로선을 놓을 수 있는 위치의 개수
int arr[MAX_W][MAX_H];
bool visit[MAX_W][MAX_H];
int answer = INF;
bool game()
{
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if (visit[cur][j])
				cur = cur + 1;
			else if (visit[cur - 1][j])
				cur = cur - 1;
		}
		if (cur != i)
			return false;
	}
	return true;
}
void dfs(int idx, int cnt)
{
	if (cnt >= 4)
		return;
	if (game()) {
		answer = min(answer, cnt);
		return;
	}
	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (visit[j][i])
				continue;
			else if (visit[j - 1][i])
				continue;
			else if (visit[j + 1][i])
				continue;
			visit[j][i] = true;
			dfs(i, cnt + 1);
			visit[j][i] = false;
		}
	}
}
int main()
{
	cin >> N >> M >> H;
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		visit[e][s] = true;
	}
	dfs(1, 0);
	if (answer == INF)
		printf("-1\n");
	else
		printf("%d\n", answer);
	return 0;
}