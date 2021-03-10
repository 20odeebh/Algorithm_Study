#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 20
int N, M;
int row, col;
vector<int> dice;
int arr[MAX_SIZE][MAX_SIZE];
void changeDice(int d)
{
	auto temp = dice;
	if (d == 1) {
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (d == 2) {
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (d == 3) {
		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[5] = temp[6];
		dice[6] = temp[2];
	}
	else {
		dice[1] = temp[2];
		dice[2] = temp[6];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}
}

int main()
{
	int tc, dir;
	cin >> N >> M;
	dice = { 0, 0, 0, 0, 0, 0, 0 };
	cin >> row >> col >> tc;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < tc; i++) {
		cin >> dir;
		switch (dir) {
		case 1:
			if (col + 1 >= M)
				continue;
			col++;
			break;
		case 2:
			if (col - 1 < 0)
				continue;
			col--;
			break;
		case 3:
			if (row - 1 < 0)
				continue;
			row--;
			break;
		case 4:
			if (row + 1 >= N)
				continue;
			row++;
			break;
		}
		changeDice(dir);
		printf("%d\n", dice[1]);
		if (arr[row][col] == 0) {
			arr[row][col] = dice[6];
		}
		else {
			dice[6] = arr[row][col];
			arr[row][col] = 0;
		}
	}
	return 0;
}