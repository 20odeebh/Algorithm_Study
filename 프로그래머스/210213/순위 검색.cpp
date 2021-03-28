#include <bits/stdc++.h>
using namespace std;
map<string, int> Map;
vector<string> temp[4];
int cnt, ans;
vector<int> v[24];
int tempsize[4];
string tempstring[4];
void go(int idx, string now) {
	if (idx == 4) {
		Map[now] = cnt;
		cnt++;
		return;
	}
	for (int i = 0; i < 2; i++) {
		go(idx + 1, now + temp[idx][i]);
	}
}
string ansstring;
void Find_ans(int idx, int MIN) {
	if (idx == 4) {
		//cout << ansstring << '\n';
		int now_num = Map[ansstring];
		auto p = lower_bound(v[now_num].begin(), v[now_num].end(), MIN);
		ans += (v[now_num].end() - p);
		return;
	}
	if (ansstring[idx] == '-') {
		for (int i = 0; i < tempsize[idx]; i++) {
			ansstring[idx] = tempstring[idx][i];
			Find_ans(idx + 1, MIN);
			ansstring[idx] = '-';
		}
	}
	else {
		Find_ans(idx + 1, MIN);
	}
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	//문자열 -> 숫자로 바꾸는 선처리
	temp[0].push_back("c"); temp[0].push_back("j"); temp[0].push_back("p");
	temp[1].push_back("b"); temp[1].push_back("f");
	temp[2].push_back("j"); temp[2].push_back("s");
	temp[3].push_back("c"); temp[3].push_back("p");
	cnt = 0;
	for (int i = 0; i < 3; i++) {
		go(1, temp[0][i]);
	}
	tempsize[0] = 3; tempsize[1] = tempsize[2] = tempsize[3] = 2;
	tempstring[0] = "cjp"; tempstring[1] = "bf"; tempstring[2] = "js"; tempstring[3] = "cp";
	int isize = info.size(), qsize = query.size();
	for (int i = 0; i < isize; i++) {
		int num = 0;
		string s = "";
		//flag가 true면 직전 앞에 공백이며, 앞자리만 넣기 위해 쓸 임시 플래그
		bool flag = true;
		for (auto c : info[i]) {
			if (c >= '0' && c <= '9') {
				num *= 10;
				num += (c - '0');
				continue;
			}
			if (flag) {
				s += c;
			}
			if (c == ' ')flag = true;
			else flag = false;
		}
		v[Map[s]].push_back(num);
	}
	for (int i = 0; i < 24; i++)sort(v[i].begin(), v[i].end());
	//for (int i = 0; i < 24; i++) {
	//	cout << i << '\n';
	//	for (auto k : v[i]) {
	//		cout << k << ' ';
	//	}
	//	cout << '\n';
	//}
	for (int i = 0; i < qsize; i++) {
		int num = 0;
		string s = "";
		//flag가 true면 직전 앞에 공백이며, 앞자리만 넣기 위해 쓸 임시 플래그
		bool flag = true;
		for (auto c : query[i]) {
			if (c >= '0' && c <= '9') {
				num *= 10;
				num += (c - '0');
				continue;
			}
			if (flag) {
				if (c == 'a') {
					flag = false;
					continue;
				}
				s += c;
			}
			if (c == ' ')flag = true;
			else flag = false;
		}
		ansstring = s;
		ans = 0;
		//cout << s << ' ' << num << '\n';
		Find_ans(0, num);
		answer.push_back(ans);
		//cout << ans << '\n';
	}
	return answer;
}