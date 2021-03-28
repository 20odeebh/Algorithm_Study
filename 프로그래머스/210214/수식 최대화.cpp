#include <bits/stdc++.h>
using namespace std;
//브루트 포스
//원래의 연산식을 q에 넣고, 모든 +-* 순서에 대하여 스택으로 연산
//마이너스 끼리 만나면 숫자를 더하는 식으로 처리해줬는데 이부분이 맞게 처리했는지 애매함
string order;
stack<pair<char, long long>> st,st2;
queue<pair<char, long long>> q,q2;
void go(char type) {
	while (!q.empty()) {
		if (q.front().first == type) {
			if (st.empty()) {
				st.push(q.front());
				q.pop();
			}
			else {
				char nc = st.top().first; long long nn = st.top().second;
				st.pop();
				if (q.front().first == '+') {
					st.push({ nc,nn + q.front().second });
					q.pop();
				}
				else if (q.front().first == '-') {
					if (q.front().first == nc) {
						st.push({ nc,nn + q.front().second });
					}
					else {
						st.push({ nc, nn - q.front().second });
					}
					q.pop();
				}
				else {
					st.push({ nc,nn * q.front().second });
					q.pop();
				}
			}
		}
		else {
			st.push(q.front());
			q.pop();
		}
	}
	while (!st.empty()) {
		st2.push(st.top());
		st.pop();
	}
	while (!st2.empty()) {
		q.push(st2.top());
		st2.pop();
	}
}
long long solution(string expression) {
	long long answer = 0;
	order = "*+-";
	char type = '+'; long long start = 0,idx=0;
	// 큐에 최초 연산식 PUSH
	if (!(expression[0] >= '0' && expression[0] <= '9')) {
		idx++;
		type = expression[0];
	}
	for (int i = idx; i < expression.size();i++) {
		if (expression[i] >= '0' && expression[i] <= '9') {
			start *= 10LL;
			start += (expression[i] - '0');
		}
		else {
			q.push({ type,start });
			start = 0;
			type = expression[i];
		}
	}
	q.push({ type,start });
	q2 = q;
	//값이 제대로 들어갔는지 확인
	//while (!q2.empty()) {
	//	cout << q2.front().first << ' ' << q2.front().second << '\n';
	//	q2.pop();
	//}
	do {
		q = q2;
		for (int i = 0; i < 3; i++) {
			go(order[i]);
		}
		answer = max(answer, abs(q.front().second));
		q.pop();
	} while (next_permutation(order.begin(), order.end()));
	return answer;
}
int main() {
	cout<<solution("100-200*300-500+20");
}