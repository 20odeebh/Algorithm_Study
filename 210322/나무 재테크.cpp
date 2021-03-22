#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int N, M, K;
int A[11][11];
deque<int> live_tree[11][11];
deque<int> dead_tree[11][11];
int arr[11][11];
int dirRow[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dirCol[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
void spring()
{
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			auto& t = live_tree[r][c];
			auto& d = dead_tree[r][c];
			int size = t.size();
			for (int i = 0; i < size; i++) {
				int age = t.front();
				t.pop_front();
				if (arr[r][c] >= age) {
					arr[r][c] -= age;
					t.push_back(age + 1);
				}
				else {
					d.push_back(age);
				}
			}
		}
	}
}
void summer()
{
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			auto& d = dead_tree[r][c];
			int size = d.size(), age;
			for (int i = 0; i < size; i++) {
				age = d.front();
				arr[r][c] += age / 2;
				d.pop_front();
			}
		}
	}
}
void fall()
{
	int nr, nc;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			auto& t = live_tree[r][c];
			int size = t.size();
			for (int k = 0; k < size; k++) {
				if (t[k] % 5 == 0) {
					for (int i = 0; i < 8; i++) {
						nr = r + dirRow[i];
						nc = c + dirCol[i];
						if (nr < 1 || nc < 1 || nr > N || nc > N)
							continue;
						auto& nt = live_tree[nr][nc];
						nt.push_front(1);
					}
				}
			}
		}
	}
}
void winter()
{
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			arr[r][c] += A[r][c];
		}
	}
}
int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			arr[i][j] = 5;
		}
	}
	int x, y, z;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		auto &t = live_tree[x][y];
		t.push_back(z);
	}
	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}
	int answer = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			auto&t = live_tree[r][c];
			answer += t.size();
		}
	}
	printf("%d\n", answer);
	return 0;
}