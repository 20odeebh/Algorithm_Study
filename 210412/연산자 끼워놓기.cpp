#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
int n;
long long min_val = INT_MAX;
long long max_val = INT_MIN;
vector<int>v;
vector<int> op;
vector<bool> visited(15, false);
vector<int> res;

void combi(int cnt) {
	if (cnt == n - 1) {
		int idx = 0;
		long long tmp = v[idx++];
		for (auto &k : res) {
			if (k == 0)
				tmp += v[idx];
			if (k == 1)
				tmp -= v[idx];
			if (k == 2)
				tmp *= v[idx];
			if (k == 3)
				tmp /= v[idx];
			idx++;
		}
		min_val = min(min_val, tmp);
		max_val = max(max_val, tmp);
		return;
	}

	for (int i = 0; i < op.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			res.push_back(op[i]);
			combi(cnt + 1);
			res.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	

	// 연산자 조합하기 !
	for (int i = 0; i < 4; i++) {
		int cnt; cin >> cnt;
		// 0 1 2 3 
		// + - x /
		while (cnt--) {
			op.push_back(i);
		}
	}

	combi(0);

	cout << max_val << '\n';
	cout << min_val;
}