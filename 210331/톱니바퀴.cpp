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
// 6시 20분 시작

// 0에서 3번
deque<int> dq[4];
int k;
void rotate(int idx, int dir) {
	if (dir == 1) {
		int tmp = dq[idx].back();
		dq[idx].push_front(tmp);
		dq[idx].pop_back();
	}
	else {
		int tmp = dq[idx].front();
		dq[idx].push_back(tmp);
		dq[idx].pop_front();
	}

}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; i++) {
		string str; cin >> str;
		for (int j = 0; j < 8; j++)
			dq[i].push_back(str[j] - '0');
	}
	cin >> k;
	while (k--) {
		int idx, dir; cin >> idx >> dir;
		idx--;
		vector<pair<int, int>>q;
		q.push_back({ idx,dir });
		int left = idx;
		int ldir = dir;

		while (1) {
			if (left == 0)
				break;
			else {
				if (dq[left][6] != dq[left - 1][2]) {
					if (ldir == -1) {
						q.push_back({ left - 1,1 });
						ldir = 1;
					}
					else {
						q.push_back({ left - 1,-1 });
						ldir = -1;
					}
					left--;
				}
				else
					break;
			}
		}
		int right = idx;
		int rdir = dir;

		while (1) {
			if (right == 3)
				break;
			else {
				if (dq[right][2] != dq[right + 1][6]) {
					if (rdir == -1) {
						q.push_back({ right + 1,1 });
						rdir = 1;
					}
					else {
						q.push_back({ right + 1,-1 });
						rdir = -1;
					}
					right++;
				}
				else
					break;
			}
		}
		// 회전
		for (auto &k : q) {
			int idx = k.first;
			int dir = k.second;
			rotate(idx, dir);
		}
	}

	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (dq[i].front() == 1) {
			res += pow(2, i);
		}
	}
	cout << res;
}

