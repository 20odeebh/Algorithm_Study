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
// 52��
int n;
int arr[51][10];
int order[10] = { 0, };
bool visited[10] = { false, };
int res = 0;

int goGame() {
	int total = 0;
	// order�� ���� ���� ����Ǿ� ����
	int ru[4];
	int idx = 1;
	// n���� �̴� ����

	for (int i = 0; i < n; i++) {
		// �ƿ��� ���
		int out = 0;
		// ���� ����
		int j = idx;
		// �� ���� ��� �ʱ�ȭ
		for (int i = 1; i <= 3; i++) {
			ru[i] = 0;
		}
		while (1) {
			// cur ��° Ÿ�ڰ� ����
			int cur = order[j];
			int res = arr[i][cur];

			// ��Ÿ
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
			// ���� Ÿ��
			j++;
			if (j == 10)
				j = 1;
			if (out == 3) {
				// �ƿ��Ǹ� Ÿ�� ��ȣ ���� �� �̴� �ٲٱ�
				idx = j;
				break;
			}
		}
	}
	return total;
}

// ���� ��� ��ġ�ϸ� 
void select(int idx, int cnt) {
	if (cnt == 9) {
		// order�� ���� ����
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
	// �� �̴� �� ������ Ÿ�� ��� ����
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++)
			cin >> arr[i][j];
	}
	// 1�� Ÿ�� 4������ ���õ�
	visited[1] = true;
	order[4] = 1;
	select(1, 1);

	cout << res;
}