#include <bits/stdc++.h>
using namespace std;
map<string, bool> Map;
vector<string> v;
//STL vector를 사용하여 구현
//LRU 알고리즘
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int nowsize = 0, size = cities.size();
	if (cacheSize == 0)return size * 5;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			if (cities[i][j] >= 'a' && cities[i][j] <= 'z')cities[i][j] -= 32;
		}
	}
	for (int i = 0; i < size; i++) {
		if (Map[cities[i]]) {
			answer++;
			auto it = find(v.begin(), v.end(), cities[i]);
			v.erase(it);
			v.push_back(cities[i]);
		}
		else {
			answer += 5;
			nowsize++;
			Map[cities[i]] = true;
			if (nowsize > cacheSize) {
				nowsize--;
				Map[v[0]] = false;
				v.erase(v.begin());
			}
			v.push_back(cities[i]);
		}
	}
	return answer;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout<<solution(1, {"Jeju", "Pangyo", "NewYork", "newyork"});
}