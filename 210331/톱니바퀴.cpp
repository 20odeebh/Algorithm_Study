// 톱니바퀴

#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

int k;
bool change[4][2];
deque<bool> dq[4];

void check(int idx, bool d) {
	change[idx][0] = true;
	change[idx][1] = d;

	int cur = idx, left = idx - 1;
	bool flag = d;
	while (left >= 0) {
		if (dq[cur][6] == dq[left][2]) break;
		change[left][0] = true;
		change[left][1] = flag ^ 1;
		cur = left;
		left = cur - 1;
		flag ^= 1;
	}
	cur = idx;
	int right = idx + 1;
	flag = d;
	while (right < 4) {
		if (dq[cur][2] == dq[right][6]) break;
		change[right][0] = true;
		change[right][1] = flag ^ 1;
		cur = right;
		right = cur + 1;
		flag ^= 1;
	}
}

void rotation() {
	for (int idx = 0; idx < 4; idx++) {
		if (!change[idx][0]) continue;
		if (change[idx][1]) {
			dq[idx].push_front(dq[idx].back());
			dq[idx].pop_back();
		}
		else {
			dq[idx].push_back(dq[idx].front());
			dq[idx].pop_front();
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char ch;
			scanf(" %c", &ch);
			if(ch == '0') dq[i].push_back(true);
			else dq[i].push_back(false);
		}
	}
	scanf(" %d", &k);
	for (int i = 0; i < k; i++) {
		int idx, direction;
		scanf(" %d %d", &idx, &direction);
		memset(change, false, sizeof(change));
		if(direction > 0) check(idx - 1, true);
		else check(idx - 1, false);
		rotation();
	}
	int res = 0;
	for (int idx = 0; idx < 4; idx++)
		if (!dq[idx][0])
			res += (1 << idx);
	printf("%d\n", res);
	return 0;
}