#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int conveyorDurable[200];
bool conveyorRobots[200];

int main() {
	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		cin >> conveyorDurable[i];
		if (conveyorDurable[i] == 0) cnt++;
	}

	int steps = 0;
	while (true) {
		int tmpDur = conveyorDurable[2 * N - 1];
		int tmpRob = conveyorRobots[2 * N - 1];
		if (conveyorRobots[N - 1]) conveyorRobots[N - 1] = 0;
		for (int i = 2 * N - 1; i > 0; i--) {
			conveyorDurable[i] = conveyorDurable[i - 1];
			conveyorRobots[i] = conveyorRobots[i - 1];
		}
		if (conveyorRobots[N - 1]) conveyorRobots[N - 1] = 0;
		conveyorDurable[0] = tmpDur;
		conveyorRobots[0] = tmpRob;

		for (int i = N - 2; i >= 0; i--) {
			if (conveyorRobots[i] && !conveyorRobots[i + 1] && conveyorDurable[i + 1]>0) {
				swap(conveyorRobots[i], conveyorRobots[i + 1]);
				conveyorDurable[i + 1]--;
				if (conveyorDurable[i + 1] == 0) cnt++;
			}
		}

		if (!conveyorRobots[0] && conveyorDurable[0]>0) {
			conveyorRobots[0] = true;
			conveyorDurable[0]--;
			if (conveyorDurable[0] == 0) cnt++;
		}

		steps++;
		if (cnt >= K) break;
	}

	cout << steps << endl;
	return 0;
}