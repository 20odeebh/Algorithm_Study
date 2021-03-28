#include <bits/stdc++.h>
using namespace std;
int l, ml;
map<string, int> Map;
map<string, bool> check;
vector<string> order;
vector<string> v[11][21];
int MAX[11];
//idx번째 주문, 주문의 음식, 현재 코스
void go(int idx, int num, string now) {
	if (now.size() > ml)return;
	//최소 2가지 이상의 단품메뉴
	if (!check[now]) {
		check[now] = true;
		if (now.size() > 1) {
			Map[now]++;
			int temp = Map[now];
			//최소 2명이상의 주문
			if (temp > 1) {
				v[now.size()][temp].push_back(now);
				MAX[now.size()] = max(MAX[now.size()], temp);
			}
		}
	}
	if (num == l)return;
	go(idx, num + 1, now + order[idx][num]);
	go(idx, num + 1, now);

}
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	order = orders;
	int osize = order.size(), csize = course.size();
	for (int i = 0; i < csize; i++) {
		MAX[course[i]] = 0;
	}
	//ml은 course중 가장 긴 길이
	ml = course[csize - 1];
	for (int i = 0; i < osize; i++) {
		sort(order[i].begin(), order[i].end());
		//l은 order[i] 스트링의 길이
		l = order[i].size();
		check.clear();
		go(i, 0, "");
	}
	for (int i = 0; i < csize; i++) {
		for (string s : v[course[i]][MAX[course[i]]]) {
			answer.push_back(s);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;

}