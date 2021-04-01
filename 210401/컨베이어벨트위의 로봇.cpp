#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include<functional>
#include <set>
#include<math.h>

using namespace std;
// 15분

// 1. 벨트 회전 (유효한 범위는 0~2n-1)
// 2. 가장 먼저 벨트에 올라간 로봇부터 이동 (이건 n-1부터 이동하면되나)
// 3. 0번에 로봇 없으면 올리기
// 4. 내구도 0인칸 검사
// deque에 내구도, 로봇 여부


// 주의할 점 : 	// 내려가는 위치에서는 반드시 내려가야함 --> 로봇이 그냥 없어진다는 의미이다
int n, k;

struct INFO {
	int robot, power;
};
int res = 0;
deque<INFO>dq;

bool IsEnd() {
	int cnt = 0;
	for (auto &k : dq) {
		if (k.power == 0)
			cnt++;
	}
	if (cnt >= k)
		return true;
	return false;
}

void move_belt() {
	INFO tmp = dq.back();
	dq.pop_back();
	dq.push_front(tmp);

	if (dq[n - 1].robot == 1) {
		dq[n - 1].robot = 0;
	}

	return;
}
void move_robot() {
	// 0에서 n-1로봇만 이동
	// 내려가는 위치에서는 반드시 내려가야함 
	for (int i = n - 2; i >= 0; i--) {
		if (dq[i].robot == 1) {
			if (dq[i + 1].robot == 0 && dq[i + 1].power >= 1) {
				dq[i].robot = 0;
				dq[i + 1].robot = 1;
				dq[i + 1].power--;
			}
		}
	}
	if (dq[n - 1].robot == 1) {
		dq[n - 1].robot = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++) {
		int p; cin >> p;
		dq.push_back({ 0,p });
	}
	while (1) {
		res++;

		move_belt();

		move_robot();

		if (dq[0].robot == 0 && dq[0].power>=1) {
			dq[0].robot = 1;
			dq[0].power--;
		}

		if (IsEnd())
			break;
	}
	cout << res;

}

