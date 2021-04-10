#include<iostream>
#include <algorithm>

using namespace std;
// 55분
int n;
int arr[21][21];
int res;

void cal_arr(int dir);

void move_arr(int dir, int cnt) {

	// 상
	if (dir == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 일단 이동 할 수 있으면 이동
				if (i == 0)
					continue;
				int nx = i, ny = j;
				int tmp = arr[i][j];
				arr[i][j] = 0;
				while (1) {
					if (nx == 0 || arr[nx-1][ny] != 0)
						break;
					nx--;
				}
				arr[nx][ny] = tmp;
			}
		}
	}
	// 하
	else if (dir == 1) {
		for (int i = n-1; i >=0 ; i--) {
			for (int j = 0; j < n; j++) {
				// 일단 이동 할 수 있으면 이동
				if (i == n - 1)
					continue;
				int nx = i, ny = j;
				int tmp = arr[i][j];
				arr[i][j] = 0;
				while (1) {
					if (nx == n-1 || arr[nx + 1][ny] != 0)
						break;
					nx++;
				}
				arr[nx][ny] = tmp;
			}
		}
	}
	// 우
	else if (dir == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >=0; j--) {
				// 일단 이동 할 수 있으면 이동
				if (j == n - 1)
					continue;
				int nx = i, ny = j;
				int tmp = arr[i][j];
				arr[i][j] = 0;
				while (1) {
					if (ny == n-1 || arr[nx][ny+1] != 0)
						break;
					ny++;
				}
				arr[nx][ny] = tmp;
			}
		}
	}
	// 좌
	else {
		for (int i = 0; i < n; i++) {
			for (int j =0; j <n; j++) {
				// 일단 이동 할 수 있으면 이동
				if (j == 0)
					continue;
				int nx = i, ny = j;
				int tmp = arr[i][j];
				arr[i][j] = 0;
				while (1) {
					if (ny == 0 || arr[nx][ny - 1] != 0)
						break;
					ny--;
				}
				arr[nx][ny] = tmp;
			}
		}
	}

	// 처음 움직였을 때에는 계산 진행, 하지만 계산 후 움직였을 때는 규칙에 따라 또 다시 계산하지 않는다.
	if (cnt == 0)
		cal_arr(dir);
}


// 계산 한번만 !
void cal_arr(int dir) {
	// 계산된 값이 있는지 확인
	bool flag = false;
	// 상 
	if (dir == 0) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == arr[i + 1][j]) {
					flag = true;
					arr[i][j] *= 2;
					arr[i + 1][j] = 0;
				}
			}
		}
	}
	// 하
	else if (dir == 1) {
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == arr[i - 1][j]) {
					flag = true;
					arr[i][j] *= 2;
					arr[i - 1][j] = 0;
				}
			}
		}
	}
	// 우
	else if (dir == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > 0; j--) {
				if (arr[i][j] == arr[i][j - 1]) {
					flag = true;
					arr[i][j] *= 2;
					arr[i][j - 1] = 0;
				}
			}
		}
	}
	// 좌
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1; j++) {
				if (arr[i][j] == arr[i][j + 1]) {
					flag = true;
					arr[i][j] *= 2;
					arr[i][j + 1] = 0;
				}
			}
		}
	}
	// 계산된 값이 있으면 비었으니까 다시 방향에 따라 움직이기, 단 다시 계산되면 안됨
	if (flag)
		move_arr(dir, 1);
}


void dfs(int cnt) {
	// 최대 5번이지만 5번 이동해야 최대값 구할 수 있음
	if (cnt == 5) {
		int tmp_max = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				tmp_max = max(tmp_max, arr[i][j]);
		}
		res = max(tmp_max, res);
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		// dir 방향으로 이동
		// 상태 저장
		int tmp[21][21];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				tmp[i][j] = arr[i][j];
		}
		// 이동
		move_arr(dir, 0);
		dfs(cnt + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	// 최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록
	// -> 5번이 최대인 경우의 수이다.
	// 상하좌우 이동 가능
	// 모든 경우의 수 진행해야한다.
	dfs(0);
	cout << res;
}