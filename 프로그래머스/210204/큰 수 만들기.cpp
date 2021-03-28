#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// k카운트만큼 스택에서 작은수를 뒤에서부터 빼준다.
string solution(string number, int k) {
	string answer = "";
	stack<char> st;
	st.push(number[0]);
	for (int i = 1; i < number.size(); i++) {
		bool flag = false;
		while (!st.empty()) {
			if (st.top() < number[i]) {
				if (k) {
					st.pop();
					k--;
				}
				else break;
			}
			else {
				st.push(number[i]);
				flag = true;
				break;
			}
		}
		if (flag == false)st.push(number[i]);
	}
	while (k) {
		st.pop();
		k--;
	}
	while (!st.empty()) {
		answer += st.top();
		st.pop();
	}
	reverse(answer.begin(), answer.end());
	return answer;
}