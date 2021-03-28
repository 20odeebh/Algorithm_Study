#include <bits/stdc++.h>
using namespace std;
bool c[8][9];
map<string, bool> Map;
map<long long, bool> min_check[9];
int n, m, answer;
vector<vector<string>> v;
vector<int> min_num;

//최소성을 가지는 숫자 조합을 찾아서
//후보키인지 판단한다
//순서는 갯수 1부터 열의 갯수까지

bool total_check;
int min_numsize;
long long now_num;
long long ttt = 0;
void go2(int idx, int cur_cnt, int cnt) {
	if (idx >= min_numsize)return;
	//현숫자 안더해줬을때
	go2(idx + 1, cur_cnt, cnt);
	//현숫자 더해줬을때
	now_num *= 10LL;
	now_num += min_num[idx] + 1;
	cur_cnt++;
	if (cur_cnt == cnt) {
		if (min_check[cnt][now_num])total_check = false;
	}
	else {
		go2(idx + 1, cur_cnt, cnt);
	}
	now_num /= 10LL;
}
//숫자 조합이 최소성을 가지는 여부
bool check_min(int num) {
	total_check = true;
	for (int i = 1; i < num; i++) {
		go2(0, 0, i);
	}
	return total_check;
}
void go(int idx, int cur_cnt, int cnt) {
	if (idx >= m)return;
	//해당 열을 포함하지 않은 경우의 수
	go(idx + 1, cur_cnt, cnt);


	//해당 열을 포함한 경우의 수
	min_num.push_back(idx);
	cur_cnt += 1;
	min_numsize = cur_cnt;
	//최소성을 가지지 않는다면 바로 종료
	if (check_min(cur_cnt) == false) {
		min_num.pop_back();
		return;
	}
	if (cur_cnt == cnt) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			string temp = "";
			for (int j = 0; j < cnt; j++) {
				temp += v[i][min_num[j]];
			}
			if (Map[temp]) {
				flag = false;
				break;
			}
			Map[temp] = true;
		}
		if (flag) {
			long long tt = 0;
			for (int i = 0; i < cnt; i++) {
				tt *= 10LL;
				tt += min_num[i] + 1;
			}
			min_check[cnt][tt] = true;
			answer++;
		}
		Map.clear();
	}
	else {
		go(idx + 1, cur_cnt, cnt);
	}
	min_num.pop_back();
}
int solution(vector<vector<string>> relation) {
	answer = 0;
	n = relation.size();
	m = relation[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = false;
		}
	}
	v = relation;
	for (int i = 1; i <= m; i++) {
		go(0, 0, i);
	}
	return answer;
}