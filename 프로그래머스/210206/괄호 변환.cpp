#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
string global_p;
string global_ans;
stack<char> st;
//설명에 따라 그대로 재귀 구현
void go(int start, int end) {
	if (start >= end)return;
	if ((end - start + 1) == 2) {
		global_ans += "()";
		return;
	}
	int lcnt = 0, rcnt = 0;
	bool flag = true;
	//cout << start << ' ' << end << '\n';
	for (int i = start; i <= end; i++) {
		if (global_p[i] == '(') {
			if (flag)st.push('(');
			lcnt++;
		}
		else {
			if (st.empty()) {
				flag = false;
			}
			else st.pop();
			rcnt++;
		}
		//cout << "확인 " << i << ' ' << flag << ' ' << lcnt << ' ' << rcnt << '\n';
		if (lcnt == rcnt) {
			if (flag) {
				for (int j = start; j <= i; j++) {
					global_ans += global_p[j];
				}
				go(i + 1, end);
			}
			else {
				global_ans += '(';
				go(i + 1, end);
				global_ans += ')';
				for (int j = start + 1; j < i; j++) {
					if (global_p[j] == '(')global_ans += ')';
					else global_ans += '(';
				}
			}
			break;
		}
	}
}
string solution(string p) {
	global_p = p;
	global_ans = "";
	go(0, p.size() - 1);
	return global_ans;
}