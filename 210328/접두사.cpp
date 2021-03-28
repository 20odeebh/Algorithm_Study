#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include<functional>

using namespace std;
vector<string> v;
vector<string> res;
int n;
int total = 0;

// 그리디 알고리즘: 가장 긴 순서대로 넣으면 가장 많이 넣을 수 있음
// map을 사용해서 첫번째 알파벳 별로 저장해 연산 속도 감소

map<char, vector<string>>m;

bool cmp(string a, string b) {
	return a.size() > b.size();
}

bool isSame(string str, string k) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != k[i])
			return false;
	}
	return true;
}

// 갈 수 있는가?
bool canGo(string str) {
	if (m[str[0]].empty())
		return true;
	// 현재 str이 다른 문자열의 접두가사 된다면 false
	for (auto &k : m[str[0]]) {
		if (k.size() >= str.size()) {
			if (isSame(str, k))
				return false;
		}
	}
	return true;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		v.push_back(str);
	}
	sort(v.begin(),v.end(),cmp);

	for (int i = 0; i < v.size();i++) {
		if (canGo(v[i])) {
			m[v[i][0]].push_back(v[i]);
		}
	}

	for (auto &k : m) {
		total += k.second.size();
	}
	cout << total;
}

