#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>
#include <memory.h>
#include <unordered_map>

using namespace std;
int n, l;
int arr[101][101];
bool selected[101][101] = { false, };
int cnt = 0;

void cal() {
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 1; j < n; j++) {
			int gap = arr[i][j] - arr[i][j - 1];
			// 1. 2이상 차이나면 진행 불가
			if (abs(gap) >= 2) {
				flag = false;
				break;
			}
			else if (gap == 1) {
				// 뒤로 l칸 확보 필요(단, 경사로가 세워지지 않은)
				int tmp = 0;
				for (int k = j - 1; k > j - 1 - l; k--) {
					if (!selected[i][k] && arr[i][k] == arr[i][j - 1])
						tmp++;
				}
				if (tmp == l) {
					for (int k = j - 1; k > j - 1 - l; k--) {
						selected[i][k] = true;
					}
				}
				else {
					flag = false;
					break;
				}
			}
			else if (gap == -1) {
				// 앞으로 l칸 확보 필요(단, 경사로가 세워지지 않은)
				int tmp = 0;
				for (int k = j; k < j + l; k++) {
					if (!selected[i][k] && arr[i][k] == arr[i][j]) {
						tmp++;
					}
				}
				if (tmp == l) {
					for (int k = j; k < j + l; k++) {
						selected[i][k] = true;
					}
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cnt++;
	}
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	cal();
	// xy를 yx로 계산하기 위해
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			selected[i][j] = false;
	}
	int tmp[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[j][i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			arr[i][j] = tmp[i][j];
	}
	cal();

	cout << cnt;
}

