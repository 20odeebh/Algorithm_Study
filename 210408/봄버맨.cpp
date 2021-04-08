#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>

using namespace std;
// 25분
int arr[201][201];
int r, c, n;
int time = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c)
		return true;
	return false;
}

void printArr() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != 0)
				cout << 'O';
			else
				cout << '.';
		}
		cout << endl;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> n;
	time = 1;
	for (int i = 0; i < r; i++) {
		string str; cin >> str;
		for (int j = 0; j < c; j++) {
			if (str[j] == '.')
				arr[i][j] = 0;
			else
				arr[i][j] = time;
		}
	}

	if (n == 1) {
		printArr();
		exit(0);
	}

	while (1) {
		time++;
		// 현재 폭탄이 아닌 곳에 대해 폭탄 설치 (2)
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 0)
					arr[i][j] = time;
			}
		}
		if (time == n)
			break;

		time++;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				// 현재 터저야할 폭탄에 대해서 상하좌우 터트리기
				if (arr[i][j] != 0 && arr[i][j] < time - 1) {
					arr[i][j] = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						// 주변에 다른 폭탄이 있으면 터트리기
						if (IsRange(nx, ny) && arr[nx][ny] == time - 1) {
							arr[nx][ny] = 0;
						}
					}
				}
			}
		}
		if (time == n)
			break;
	}

	printArr();

}