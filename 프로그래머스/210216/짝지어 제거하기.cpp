#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<char> st;
// 스택 탑이 같다면 pop 아니면 push
int solution(string s)
{
	for (int i = 0; i < s.size(); i++) {
		if (st.empty()) {
			st.push(s[i]);
			continue;
		}
		if (s[i] == st.top())st.pop();
		else st.push(s[i]);
	}
	if (st.empty())return 1;
	else return 0;
}