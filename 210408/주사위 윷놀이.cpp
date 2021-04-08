#include <bits/stdc++.h>

using namespace std;

map<int, int> r = {
	{ 0, 2 },{ 2, 4 },{ 4, 6 },
	{ 6, 8 },{ 8, 10 },{ 10, 12 },
	{ 12, 14 },{ 14, 16 },{ 16, 18 },
	{ 18, 20 },{ 20, 22 },{ 22, 24 },
	{ 24, 26 },{ 26, 28 },{ 28, 30 },
	{ 30, 32 },{ 32, 34 },{ 34, 36 },
	{ 36, 38 },{ 38, 40 },{ 40, 50 }
};

map<int, int> b = {
	{ 10, 13 },{ 13, 16 },{ 16, 19 },
	{ 19, 25 },{ 20, 22 },{ 22, 24 },
	{ 24, 25 },{ 30, 28 },{ 28, 27 },
	{ 27, 26 },{ 26, 25 },
};

map<int, int> b_goal = {
	{ 25, 30 },{ 30, 35 },{ 35, 40 },{ 40, 50 }
};

int ans;
vector<int> die;

void move(vector<int> &arr) {
	pair<int, int> locate[4] = {
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 }
	};

	bool tok = true;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		int mal = arr[i];
		int present = locate[mal].first;
		int dir = locate[mal].second;
		int cnt = die[i];

		if (present == 50) continue;
		 
		for (int j = 0; j < cnt; j++) {
			if (dir == 0) present = r[present];
			else if (dir == 1) present = b[present];
			else if (dir == 2) present = b_goal[present];
			
			if (present == 25) dir = 2;
			else if (present == 50) break;
		}

		if (present == 50) {
			locate[mal].first = present;
		}
		else {
			if (dir == 0 && (present == 10 || present == 20 || present == 30)) {
				dir = 1;
			}

			bool ok = true;
			for (int j = 0; j < 4; j++) {
				if (mal != j) {
					if (present == locate[j].first && 
						( present == 40 || dir == locate[j].second)) {
						ok = false;
					}
				}
			}

			if (ok) {
				locate[mal].first = present;
				locate[mal].second = dir;
				sum += present;
			}
			else {
				tok = false;
			}
		}
	}
		
	if (tok) {
		ans = max(ans, sum);
	}
}

void go(int idx, vector<int> &arr) {
	if (idx == 10) {
		move(arr);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		arr[idx] = i;
		go(idx + 1, arr);
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		die.push_back(x);
	}

	vector<int> arr(10);
	go(0, arr);

	cout << ans << '\n';
}
