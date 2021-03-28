#include <bits/stdc++.h>
using namespace std;
map<string, int> Map;
//맵을 이용하여 그대로 구현
vector<int> solution(string msg) {
	vector<int> answer;
	string now = "";
	for (char i = 'A'; i <= 'Z'; i++) {
		string t = "";
		t += i;
		Map[t] = i - 'A' + 1;
	}
	int idx = 27;
	for (int i = 0; i < msg.size(); i++) {
		now += msg[i];
		if (!Map[now]) {
			string temp = now.substr(0, now.size() - 1);
			answer.push_back(Map[temp]);
			Map[now] = idx++;
			now = msg[i];
		}
	}
	answer.push_back(Map[now]);
	return answer;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
}