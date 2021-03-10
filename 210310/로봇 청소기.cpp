#include <iostream>
using namespace std;
int N, M;
int arr[50][50];
bool visit[50][50];
enum DIR {
	NORTH = 0,
	EAST,
	SOUTH,
	WEST
};
typedef struct Cleaner {
	int row;
	int col;
	int dir;
};
void setting()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visit[i][j] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
		}
	}
}
bool A(Cleaner& clr, int& cnt)
{
	Cleaner next = clr;
	if (clr.dir == DIR::NORTH &&
		visit[clr.row][clr.col - 1] == false) {
		next.col -= 1;
		next.dir = DIR::WEST;
	}
	else if (clr.dir == DIR::EAST &&
		visit[clr.row - 1][clr.col] == false) {
		next.row -= 1;
		next.dir = DIR::NORTH;
	}
	else if(clr.dir == DIR::SOUTH &&
		visit[clr.row][clr.col + 1] == false){
		next.col += 1;
		next.dir = DIR::EAST;
	}
	else if (clr.dir == DIR::WEST &&
		visit[clr.row + 1][clr.col] == false) {
		next.row += 1;
		next.dir = DIR::SOUTH;
	}
	else {
		//왼쪽 방향에 이미 청소한 칸임
		return false;
	}

	//왼쪽 방향 칸이 범위를 벗어남
	if (next.col < 0 || next.row < 0 ||
		next.row >= N || next.col >= M) {
		return false;
	}
	//왼쪽 방향 칸이 벽임
	else if (arr[next.row][next.col] == 1) {
		return false;
	}
	else {
		visit[next.row][next.col] = true;
		clr = next;
		cnt += 1;
		return true;
	}
}
bool B(Cleaner& clr)
{
	Cleaner next = clr;
	if (clr.dir == DIR::NORTH &&
		(visit[clr.row][clr.col - 1] == true ||
		arr[clr.row][clr.col - 1] == 1)) {
		next.dir = DIR::WEST;
	}
	else if (clr.dir == DIR::EAST &&
		(visit[clr.row - 1][clr.col] == true ||
		arr[clr.row - 1][clr.col] == 1)) {
		next.dir = DIR::NORTH;
	}
	else if (clr.dir == DIR::SOUTH &&
		(visit[clr.row][clr.col + 1] == true || 
		arr[clr.row][clr.col + 1] == 1)) {
		next.dir = DIR::EAST;
	}
	else if (clr.dir == DIR::WEST &&
		(visit[clr.row + 1][clr.col] == true ||
		arr[clr.row + 1][clr.col] == 1)) {
		next.dir = DIR::SOUTH;
	}
	else {
		return false;
	}
	clr = next;
	return true;
}
bool C(Cleaner& clr)
{
	Cleaner next = clr;
	if (
		(visit[clr.row - 1][clr.col] == true || arr[clr.row - 1][clr.col] == 1) &&
		(visit[clr.row + 1][clr.col] == true || arr[clr.row + 1][clr.col] == 1) &&
		(visit[clr.row][clr.col - 1] == true || arr[clr.row][clr.col - 1] == 1) &&
		(visit[clr.row][clr.col + 1] == true || arr[clr.row][clr.col + 1] == 1)
		)
	{
		if (next.dir == DIR::NORTH) {
			next.row += 1;
		}
		else if (next.dir == DIR::SOUTH) {
			next.row -= 1;
		}
		else if (next.dir == DIR::EAST) {
			next.col -= 1;
		}
		else if (next.dir == DIR::WEST) {
			next.col += 1;
		}
		clr = next;
		return true;
	}

	return false;
}
bool D(Cleaner& clr)
{
	if (
		(visit[clr.row - 1][clr.col] == true || arr[clr.row - 1][clr.col] == 1) &&
		(visit[clr.row + 1][clr.col] == true || arr[clr.row + 1][clr.col] == 1) &&
		(visit[clr.row][clr.col - 1] == true || arr[clr.row][clr.col - 1] == 1) &&
		(visit[clr.row][clr.col + 1] == true || arr[clr.row][clr.col + 1] == 1)
		)
	{
		if (clr.dir == DIR::NORTH && arr[clr.row + 1][clr.col] == 1) {
			return true;
		}
		else if (clr.dir == DIR::SOUTH && arr[clr.row - 1][clr.col] == 1) {
			return true;
		}
		else if (clr.dir == DIR::EAST && arr[clr.row][clr.col - 1] == 1) {
			return true;
		}
		else if (clr.dir == DIR::WEST && arr[clr.row][clr.col + 1] == 1) {
			return true;
		}
	}
	return false;
}
void sim(Cleaner& clr)
{
	int cnt = 0;
	//현재 위치 청소
	visit[clr.row][clr.col] = true;
	cnt++;
	while (1) {
		if (D(clr)) {
			break;
		}
		if (C(clr)) {
			continue;
		}
		if (B(clr)) {
			continue;
		}
		if (A(clr, cnt)) {
			continue;
		}
	}
	printf("%d\n", cnt);
}
int main()
{
	Cleaner clr;
	cin >> N >> M;
	cin >> clr.row >> clr.col >> clr.dir;
	setting();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	sim(clr);
	return 0;
}