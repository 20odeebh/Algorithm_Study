// 특이한 자석

#include <stdio.h>
#include <deque>

using namespace std;

int k;
deque<bool> dq[4];

void right_rotate(int num) {
	dq[num].push_front(dq[num].back());
	dq[num].pop_back();
}

void left_rotate(int num) {
	dq[num].push_back(dq[num].front());
	dq[num].pop_front();
}

void rotate(int num, int d) {
	int is_rotate[4] = { 0, };
	is_rotate[num] = d;

	int idx = num - 1;
	int nd = -d;
	while (idx >= 0) {
		if (dq[idx + 1][6] == dq[idx][2]) break;
		is_rotate[idx--] = nd;
		nd = -nd;
	}
	idx = num + 1;
	nd = -d;
	while (idx < 4) {
		if (dq[idx - 1][2] == dq[idx][6]) break;
		is_rotate[idx++] = nd;
		nd = -nd;
	}
	for (int i = 0; i < 4; i++) {
		if (!is_rotate[i]) continue;
		if (is_rotate[i] > 0) right_rotate(i);
		else left_rotate(i);
	}
}

int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		for (int i = 0; i < 4; i++) dq[i].clear();
		scanf(" %d", &k);
		for (int i = 0; i < 4; i++) {
			dq[i].resize(8);
			for (int j = 0; j < 8; j++)
				scanf(" %d", &dq[i][j]);
		}
		while (k--) {
			int num, d;
			scanf(" %d %d", &num, &d);
			rotate(num - 1, d);
		}
		int ret = 0;
		for (int i = 0; i < 4; i++)
			if (dq[i][0]) ret += (1 << i);
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}