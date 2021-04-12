#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;
#define INF 987654321
#define MAX_SIZE 20
int N, W, H;
int arr[MAX_SIZE][MAX_SIZE];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
int answer = INF;
int state[MAX_SIZE][MAX_SIZE];
void remove_block(int row, int col, int cnt)
{
	int nr, nc;
	arr[row][col] = 0;
	for (int c = 1; c < cnt; c++) {
		for (int i = 0; i < 4; i++) {
			nr = row + dirRow[i] * c;
			nc = col + dirCol[i] * c;
			if (nr < 0 || nc < 0 || nr >= H || nc >= W)
				continue;
			if (arr[nr][nc] >= 2) {
				remove_block(nr, nc, arr[nr][nc]);
			}
			arr[nr][nc] = 0;
		}
	}
}
void drop_block()
{
	for (int c = 0; c < W; c++) {
		stack<int> s;
		for (int r = 0; r < H; r++) {
			if (arr[r][c] >= 1)
				s.push(arr[r][c]);
		}
		for (int r = H - 1; r >= 0; r--) {
			if (!s.empty()) {
				arr[r][c] = s.top();
				s.pop();
			}
			else
				arr[r][c] = 0;
		}
	}
}
int get_result()
{
	int sum = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] != 0)
				sum++;
		}
	}
	return sum;
}
void dfs(int toPick)
{
	if (toPick == 0) {
		answer = min(answer, get_result());
		return;
	}
	int temp[MAX_SIZE][MAX_SIZE];
	memcpy(temp, arr, sizeof(temp));
	for (int c = 0; c < W; c++) {
		//remove
		for (int r = 0; r < H; r++) {
			if (arr[r][c] >= 1) {
				remove_block(r, c, arr[r][c]);
				drop_block();
				break;
			}
		}
		dfs(toPick - 1);
		memcpy(arr, temp, sizeof(temp));
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(arr, 0, sizeof(arr));
		answer = INF;
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
		}
		dfs(N);
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}