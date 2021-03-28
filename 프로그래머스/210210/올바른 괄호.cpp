#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> st;
//스택활용
bool solution(string s)
{
	bool answer = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')st.push(i);
		else {
			if (st.empty()) {
				return false;
			}
			else {
				st.pop();
			}
		}
	}
	if (!st.empty())return false;
	return answer;
}