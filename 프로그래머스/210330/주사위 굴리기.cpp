#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dice[7] = { 0 }, idx[3] = { 6,5,3 }, arr[21][21];
int dx[5] = { 0,0,0,-1,1 }, dy[5] = { 0,1,-1,0,0 };
//주사위의 바닥면,아랫면,오른쪽면인덱스만 저장하여
//주사위의 반대편인덱스 합은 7인것을 사용해 3개만 조절해준다.
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, x, y, K;
	cin >> n >> m >> x >> y >> K;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (K--) {
		int t;
		cin >> t;
		int nx = x + dx[t], ny = y + dy[t];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (t == 1) {
			int temp = 7 - idx[0];
			idx[0] = idx[2]; idx[2] = temp;
		}
		else if (t == 2) {
			int temp = 7 - idx[2];
			idx[2] = idx[0]; idx[0] = temp;
		}
		else if (t == 3) {
			int temp = 7 - idx[1];
			idx[1] = idx[0]; idx[0] = temp;
		}
		else {
			int temp = 7 - idx[0];
			idx[0] = idx[1]; idx[1] = temp;
		}
		//바닥면 복사
		if (arr[nx][ny]) {
			dice[idx[0]] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		else {
			arr[nx][ny] = dice[idx[0]];
		}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << arr[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
		//for (int i = 0; i < 3; i++)cout << dice[idx[i]] << ' ';
		//cout << '\n';
		cout << dice[7 - idx[0]] << '\n';

		x = nx; y = ny;
	}

}