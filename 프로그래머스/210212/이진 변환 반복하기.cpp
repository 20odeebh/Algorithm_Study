#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int a, b;
//그대로 구현
string go(string s) {
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')cnt0++;
		else cnt1++;
	}
	string ret = "";
	b += cnt0;
	while (cnt1) {
		if (cnt1 % 2)ret += '1';
		else ret += '0';
		cnt1 /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
vector<int> solution(string s) {
	vector<int> answer;
	a = 0; b = 0;
	while (s != "1") {
		s = go(s);
		a++;
	}
	answer.push_back(a);
	answer.push_back(b);
	return answer;
}