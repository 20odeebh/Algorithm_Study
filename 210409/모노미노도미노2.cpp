#include<iostream>
#include <algorithm>

using namespace std;
// 있으면 1, 없으면 0

int arr[10][10];
int n;
int res = 0;

void put_right(int t, int x, int y) {
	// 1x1일때
	if (t == 1) {
		int nx = x;
		int ny = y;
		while (1) {
			if (arr[nx][ny + 1] == 1 || ny + 1 > 9)
				break;
			ny++;
		}
		arr[nx][ny] = 1;
	}
	// 1x2일 때
	else if (t == 2) {
		int nx[2] = { x,x };
		int ny[2] = { y,y + 1 };
		while (1) {
			bool flag = true;
			for (int i = 0; i < 2; i++) {
				if (ny[i] + 1> 9 || arr[nx[i]][ny[i] + 1] == 1) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
			ny[0]++;
			ny[1]++;
		}
		arr[nx[0]][ny[0]] = 1;
		arr[nx[1]][ny[1]] = 1;
	}
	else {
		int nx[2] = { x,x + 1 };
		int ny[2] = { y,y };
		while (1) {
			bool flag = true;
			for (int i = 0; i < 2; i++) {
				if (ny[i] + 1> 9 || arr[nx[i]][ny[i] + 1] == 1) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
			ny[0]++;
			ny[1]++;
		}
		arr[nx[0]][ny[0]] = 1;
		arr[nx[1]][ny[1]] = 1;
	}
}

void put_down(int t, int x, int y) {
	// 1x1일때
	if (t == 1) {
		int nx = x;
		int ny = y;
		while (1) {
			if (arr[nx + 1][ny] == 1 || nx + 1 > 9)
				break;
			nx++;
		}
		arr[nx][ny] = 1;
	}
	// 1x2일 때
	else if (t == 2) {
		int nx[2] = { x,x };
		int ny[2] = { y,y + 1 };
		while (1) {
			bool flag = true;
			for (int i = 0; i < 2; i++) {
				if (nx[i] + 1> 9 || arr[nx[i] + 1][ny[i]] == 1) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
			nx[0]++;
			nx[1]++;
		}
		arr[nx[0]][ny[0]] = 1;
		arr[nx[1]][ny[1]] = 1;
	}
	else {
		int nx[2] = { x,x + 1 };
		int ny[2] = { y,y };
		while (1) {
			bool flag = true;
			for (int i = 0; i < 2; i++) {
				if (nx[i] + 1 > 9 || arr[nx[i] + 1][ny[i]] == 1) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
			nx[0]++;
			nx[1]++;
		}
		arr[nx[0]][ny[0]] = 1;
		arr[nx[1]][ny[1]] = 1;
	}
	return;
}

// 연속해서 터지는 부분 생기는 것 주의
void remove_down() {
	for (int i = 9; i >= 6; i--) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			res++;
			for (int k = i; k >= 4; k--) {
				for (int l = 0; l < 4; l++)
					arr[k][l] = arr[k - 1][l];
			}
			// 다시 계산..!!!! 다시 한칸 늘려서 검사
			i++;
		}
	}
}

void remove_right() {
	for (int i = 9; i >= 6; i--) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			if (arr[j][i] == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			res++;
			for (int k = i; k >= 4; k--) {
				for (int l = 0; l < 4; l++)
					arr[l][k] = arr[l][k - 1];
			}
			i++;
		}
	}
}

void print_arr() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void check_blue() {
	int cnt = 0;
	// 연한 부분 몇 개 들어있는지 확인
	for (int j = 4; j <= 5; j++) {
		for (int i = 0; i < 4; i++) {
			if (arr[i][j] == 1) {
				cnt++;
				break;
			}
		}
	}
	// 그 수만큼 이동
	while (cnt--) {
		for (int j = 8; j >= 3; j--) {
			for (int i = 0; i < 4; i++) {
				arr[i][j + 1] = arr[i][j];
			}
		}
	}
}


void check_green() {
	int cnt = 0;
	// 연한 부분 몇 개 들어있는지 확인
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1) {
				cnt++;
				break;
			}
		}
	}
	// 그 수만큼 이동
	while (cnt--) {
		for (int i = 8; i >= 3; i--) {
			for (int j = 0; j < 4; j++) {
				arr[i + 1][j] = arr[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		put_down(t, x, y);
		put_right(t, x, y);
		remove_down();
		remove_right();
		check_blue();
		check_green();
	}
	cout << res << '\n';
	int remain = 0;
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1)
				remain++;
			if (arr[j][i] == 1)
				remain++;
		}
	}
	cout << remain;
}