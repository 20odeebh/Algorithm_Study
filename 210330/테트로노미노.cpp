#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500;
typedef struct
{
	int y, x;
}Dir;
Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
int N, M;
int cell[MAX][MAX];
bool visited[MAX][MAX];
int DFS(int y, int x, int cnt)
{
	if (cnt == 4)
		return cell[y][x];
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && !visited[nextY][nextX])
		{
			visited[nextY][nextX] = true;
			sum = max(sum, cell[y][x] + DFS(nextY, nextX, cnt + 1));
			visited[nextY][nextX] = false;
		}
	}
	return sum;
}
int except(int y, int x)
{
	int result = 0;
	if (y >= 1 && x >= 1 && x < M - 1)
		result = max(result, cell[y][x - 1] + cell[y][x] + cell[y - 1][x] + cell[y][x + 1]);
	if (y >= 1 && y < N - 1 && x < M - 1)
		result = max(result, cell[y - 1][x] + cell[y][x] + cell[y][x + 1] + cell[y + 1][x]);
	if (y >= 0 && y < N - 1 && x < M - 1)
		result = max(result, cell[y][x - 1] + cell[y][x] + cell[y + 1][x] + cell[y][x + 1]);
	if (y >= 1 && y < N - 1 && x >= 1)
		result = max(result, cell[y - 1][x] + cell[y][x] + cell[y][x - 1] + cell[y + 1][x]);
	return result;
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> cell[i][j];
	int result = 0;
	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			result = max(result, DFS(i, j, 1));
			result = max(result, except(i, j));
			visited[i][j] = false;
		}
	cout << result << endl;
	return 0;
}
