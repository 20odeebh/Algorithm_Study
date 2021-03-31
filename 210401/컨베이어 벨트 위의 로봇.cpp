// 컨베이어 벨트 위의 로봇

#include <stdio.h>
#include <deque>

using namespace std;

int n, k;
deque<pair<bool, int>> dq;

void move_belt() {
	if (dq[n - 1].first) dq[n - 1].first = false;
	dq.push_front(dq.back());
	dq.pop_back();
}

void move_robot() {
	if (dq[n - 1].first) dq[n - 1].first = false;
	for (int i = n - 2; i >= 0; i--) {
		if (!dq[i].first || dq[i + 1].first || !dq[i + 1].second) continue;
		dq[i + 1].first = true;
		dq[i + 1].second--;
		dq[i].first = false;
		if (!dq[i + 1].second) k--;
	}
}

void put_robot() {
	if (dq[0].second) {
		dq[0].first = true;
		dq[0].second--;
		if (!dq[0].second) k--;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	dq.resize(n << 1);
	for (int i = 0; i < (n << 1); i++) scanf(" %d", &dq[i].second);
	int t = 0;
	while (k > 0) {
		t++;
		move_belt();
		move_robot();
		put_robot();
	}
	printf("%d\n", t);
	return 0;
}