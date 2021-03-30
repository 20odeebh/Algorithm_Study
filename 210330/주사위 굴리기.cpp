#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 21
int field[MAX_SIZE][MAX_SIZE];
int Width, Height;
int K, row, col;
vector<int> dice(7, 0);
//ÁÖ»çÀ§ ¹Ø¸éÀº ÀÎµ¦½º 4
void change_dice(int dir)
{
	auto temp = dice;
	switch (dir) {
	case 1:
		dice[2] = temp[6];
		dice[6] = temp[4];
		dice[4] = temp[5];
		dice[5] = temp[2];
		break;
	case 2:
		dice[6] = temp[2];
		dice[4] = temp[6];
		dice[5] = temp[4];
		dice[2] = temp[5];
		break;
	case 3:
		dice[1] = temp[2];
		dice[2] = temp[3];
		dice[3] = temp[4];
		dice[4] = temp[1];
		break;
	case 4:
		dice[2] = temp[1];
		dice[3] = temp[2];
		dice[4] = temp[3];
		dice[1] = temp[4];
		break;
	}
}
bool move_dice(int dir)
{
	switch (dir) {
	case 1:
		if (col + 1 >= Width)
			return false;
		col++;
		break;
	case 2:
		if (col - 1 < 0)
			return false;
		col--;
		break;
	case 3:
		if (row - 1 < 0)
			return false;
		row--;
		break;
	case 4:
		if (row + 1 >= Height)
			return false;
		row++;
		break;
	}
	change_dice(dir);
	if (field[row][col] == 0) {
		field[row][col] = dice[4];
	}
	else {
		dice[4] = field[row][col];
		field[row][col] = 0;
	}
	return true;
}
int main()
{
	int order;
	cin >> Height >> Width;
	cin >> row >> col >> K;
	for (int i = 0; i < Height; i++)
		for (int j = 0; j < Width; j++)
			cin >> field[i][j];
	for (int i = 0; i < K; i++) {
		cin >> order;
		if (move_dice(order)) {
			printf("%d\n", dice[2]);
		}
	}
	return 0;
}