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

using namespace std;
// 52분
int n;
int arr[51][10];
int order[10] = { 0, };
bool visited[10] = { false, };
int res = 0;

int goGame() {
	int total = 0;
	// order에 선수 순서 저장되어 있음
	int ru[4];
	int idx = 1;
	// n번의 이닝 시작

	for (int i = 0; i < n; i++) {
		// 아웃된 사람
		int out = 0;
		// 시작 순서
		int j = idx;
		// 각 루의 사람 초기화
		for (int i = 1; i <= 3; i++) {
			ru[i] = 0;
		}
		while (1) {
			// cur 번째 타자가 진행
			int cur = order[j];
			int res = arr[i][cur];

			// 안타
			if (res == 1) {
				if (ru[3] == 1) {
					total++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {
					ru[3] = 1;
					ru[2] = 0;
				}
				if (ru[1] == 1) {
					ru[2] = 1;
					ru[1] = 0;
				}
				ru[1] = 1;
			}
			else if (res == 2) {
				if (ru[3] == 1) {
					total++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {
					total++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {
					ru[3] = 1;
					ru[1] = 0;
				}
				ru[2] = 1;
			}
			else if (res == 3) {
				for (int k = 1; k <= 3; k++) {
					if (ru[k] == 1) {
						total++;
						ru[k] = 0;
					}
				}
				ru[3] = 1;
			}
			else if (res == 4) {
				total++;
				for (int k = 1; k <= 3; k++) {
					if (ru[k] == 1) {
						total++;
						ru[k] = 0;
					}
				}
			}
			else {
				out++;
			}
			// 다음 타수
			j++;
			if (j == 10)
				j = 1;
			if (out == 3) {
				// 아웃되면 타자 번호 저장 후 이닝 바꾸기
				idx = j;
				break;
			}
		}
	}
	return total;
}

// 선수 모두 배치하면 
void select(int idx, int cnt) {
	if (cnt == 9) {
		// order로 게임 진행
		res = max(res, goGame());
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (!visited[i] && order[idx] == 0) {
			order[idx] = i;
			visited[i] = true;
			if (idx + 1 == 4) {
				select(idx + 2, cnt + 1);
			}
			else
				select(idx + 1, cnt + 1);
			visited[i] = false;
			order[idx] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	// 각 이닝 별 선수의 타자 결과 저장
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++)
			cin >> arr[i][j];
	}
	// 1번 타자 4번으로 선택됨
	visited[1] = true;
	order[4] = 1;
	select(1, 1);

	cout << res;
}