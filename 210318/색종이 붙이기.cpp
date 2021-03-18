#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 11
#define INF 987654321
int arr[SIZE][SIZE];
int answer = INF;
vector<int> paper(6, 5);
bool visit[SIZE][SIZE];
bool IsAttachPaper(int row, int col, int size)
{
	if (row + size > SIZE || col + size > SIZE)
		return false;
	if (paper[size] == 0)
		return false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[row + i][col + j] != 1
				|| visit[row + i][col + j] == true) {
				return false;
			}
		}
	}
	return true;
}
void AttachedPaper(int row, int col, int size)
{
	paper[size]--;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			visit[row + i][col + j] = true;
		}
	}
}
void DettachedPaper(int row, int col, int size)
{
	paper[size]++;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			visit[row + i][col + j] = false;
		}
	}
}
bool IsSucceed()
{
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false)
				return false;
		}
	}
	return true;
}
void dfs(int row, int col)
{
	int r = row, c = col;
	for (; r < SIZE; r++) {
		for (; c < SIZE; c++) {
			if (arr[r][c] == 1 && visit[r][c] == false) {
				for (int k = 1; k <= 5; k++) {
					if (IsAttachPaper(r, c, k)) {
						AttachedPaper(r, c, k);
						dfs(r, c);
						DettachedPaper(r, c, k);
					}
				}
				return;
			}
		}
		c = 0;
	}
	if (!IsSucceed())
		return;
	int sum = 0;
	for (int i = 1; i < paper.size(); i++)
		sum += 5 - paper[i];
	answer = min(answer, sum);
}
bool IsZero()
{
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (arr[i][j] != 0)
				return false;
		}
	}
	return true;
}
int main()
{
	for (int i = 1; i < SIZE; i++)
		for (int j = 1; j < SIZE; j++)
			cin >> arr[i][j];
	if (IsZero()) {
		printf("0\n");
		return 0;
	}
	dfs(1, 1);
	if (answer == INF)
		printf("-1\n");
	else
		printf("%d\n", answer);
	return 0;
}