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
#include <memory.h>
#include <unordered_map>

using namespace std;
int t;
deque<int> v[1001];
// 2번 인덱스와 6번 인덱스
int answer = 0;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.size(); j++) {
			v[i].push_back(str[j] - '0');
		}
	}
	int k; cin >> k;
	while (k--) {
		int num, dir;
		cin >> num >> dir;
		num--;
		vector<pair<int, int>> rotate;
		rotate.push_back({ num,dir });
		int ridx = num;
		int rdir = dir;
		while (1) {
			if (ridx == t - 1)
				break;
			if (v[ridx][2] == v[ridx + 1][6])
				break;
			if (rdir == 1) {
				rotate.push_back({ ridx + 1,-1 });
				rdir = -1;
			}
			else {
				rotate.push_back({ ridx + 1,1 });
				rdir = 1;
			}
			ridx++;
		}
		int lidx = num;
		int ldir = dir;
		while (1) {
			if (lidx == 0)
				break;
			if (v[lidx][6] == v[lidx - 1][2])
				break;
			if (ldir == 1) {
				rotate.push_back({ lidx - 1,-1 });
				ldir = -1;
			}
			else {
				rotate.push_back({ lidx - 1,1 });
				ldir = 1;
			}
			lidx--;
		}

		// rotate 처리 
		for (auto &k : rotate) {
			//  반시계
			if (k.second == -1) {
				int tmp = v[k.first].front();
				v[k.first].pop_front();
				v[k.first].push_back(tmp);
			}
			// 시계
			else {
				int tmp = v[k.first].back();
				v[k.first].pop_back();
				v[k.first].push_front(tmp);
			}
		}
	}
	for (int i = 0; i < t; i++) {
		if (v[i].front() == 1)
			answer++;
	}
	cout << answer;
}