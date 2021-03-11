#include <iostream>
using namespace std;
/*
1. 경사로를 이미 놓았는지 확인
2. 경사로를 놓을 수 있는 길이, 높이인지 확인
3. 경사로를 놓은 후 높이를 갱신한다.
*/
#define MAX_SIZE 100
#define FORWARD		0
#define BACKWARD	1
#define WIDTH		0
#define HEIGHT		1
int N, L;
int arr[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE][2];
bool IsMakeLoad(int row, int col, int flag, int dir, int h)
{
	int nh = dir == 1 ? h : h - 1;
	if (flag == WIDTH) {
		//가로
		if (dir == FORWARD) {
			//순방향
			for (int i = 0; i < L; i++) {
				if (col + i >= N)
					return false;
				if (nh != arr[row][col + i])
					return false;
			}
		}
		else {
			//역방향
			if (col - L < 0)
				return false;
			for (int i = 1; i <= L; i++) {
				if (nh != arr[row][col - i])
					return false;
				if (visit[row][col - i][flag] == true)
					return false;
			}
		}
	}
	else {
		//세로
		if (dir == FORWARD) {

			for (int i = 0; i < L; i++) {
				if (row + i >= N)
					return false;
				if (nh != arr[row + i][col])
					return false;
			}
		}
		else {
			if (row - L < 0)
				return false;
			for (int i = 1; i <= L; i++) {
				if (nh != arr[row - i][col])
					return false;
				if (visit[row - i][col][flag] == true)
					return false;
			}
		}
	}
	return true;
}
int check(int row, int col, int flag)
{
	int h = arr[row][col];
	int dir;
	if (flag == WIDTH) {
		//세로
		while (col < N) {
			dir = h < arr[row][col];
			if (h != arr[row][col]) {
				if (abs(h - arr[row][col]) != 1)
					return false;
				if (IsMakeLoad(row, col, flag, dir, h)) {
					if (dir == FORWARD) {
						for (int k = 0; k < L; k++)
							visit[row][col + k][flag] = true;
					}
					else {
						for (int k = 1; k <= L; k++)
							visit[row][col - k][flag] = true;
					}
					h = arr[row][col];
				}
				else
					return false;
			}
			col++;
		}
	}
	else {
		while (row < N) {
			dir = h < arr[row][col];
			if (h != arr[row][col]) {
				if (abs(h - arr[row][col]) != 1)
					return false;
				if (IsMakeLoad(row, col, flag, h < arr[row][col], h)) {
					if (dir == FORWARD) {
						for (int k = 0; k < L; k++)
							visit[row + k][col][flag] = true;
					}
					else {
						for (int k = 1; k <= L; k++)
							visit[row - k][col][flag] = true;
					}
					h = arr[row][col];
				}
				else
					return false;
			}
			row++;
		}
	}
	return 1;
}
int main()
{
	int answer = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < N; i++)
		answer += check(0, i, HEIGHT);
	for (int i = 0; i < N; i++)
		answer += check(i, 0, WIDTH);
	printf("%d\n", answer);
	return 0;
}