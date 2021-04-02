#include<cmath>
#include<iostream>
#include <string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
// 41분
int r, c, k;
int res = 0;
int arr[101][101];

// 정렬 
// 등장횟수 작은것, 수가 작은것
// 숫자, 등장 횟수
bool cmp(pair<int,int> p1, pair<int,int>p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++)
			arr[i][j] = -1;
	}
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		// 꼭 3개 노노?
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}
	int rsize = 3, csize = 3;
	while (1) {
		if (res == 101)
			break;
		if (arr[r][c] == k) {
			cout << res;
			exit(0);
		}
		// 행열의 개수 구하기 ...
		// vector..? vs array ..?
		// map 사용 
		// 초기화하고 진행 

		if (rsize >= csize) {
			int max_row = -1;
			for (int i = 1; i <= rsize; i++) {
				map<int, int>m;
				for (int j = 1; j <= csize; j++) {
					if (arr[i][j] != 0 && arr[i][j]!=-1) {
						m[arr[i][j]]++;
						// 초기화
						arr[i][j] = -1;
					}
				}
				int idx = 1;
				vector<pair<int, int>>v(m.begin(), m.end());
				sort(v.begin(), v.end(), cmp);

				for (auto &k : v) {
					if (k.first == 0)
						continue;
					arr[i][idx++] = k.first;
					arr[i][idx++] = k.second;
				}
				max_row = max(max_row, idx - 1);
			}
			for (int i = 1; i <= rsize; i++) {
				for (int j = 1; j <= max_row; j++) {
					if (arr[i][j] == -1)
						arr[i][j] = 0;
				}
			}
			csize = max_row;
		}
		// C연산 조건
		else {
			int max_col = -1;
			for (int i = 1; i <= csize; i++) {
				map<int, int>m;
				for (int j = 1; j <= rsize; j++) {
					if (arr[j][i] != 0 && arr[j][i]!=-1) {
						m[arr[j][i]]++;
						// 초기화
						arr[j][i] = -1;
					}
				}
				int idx = 1;
				vector<pair<int, int>>v(m.begin(), m.end());
				sort(v.begin(), v.end(), cmp);

				for (auto &k : v) {
					arr[idx++][i] = k.first;
					arr[idx++][i] = k.second;
				}
				max_col = max(max_col, idx - 1);
			}
			for (int i = 1; i <= max_col; i++) {
				for (int j = 1; j <= csize; j++) {
					if (arr[j][i] == -1)
						arr[j][i] = 0;
				}
			}
			rsize = max_col;
		}
		res++;
	}
	cout << -1;

}