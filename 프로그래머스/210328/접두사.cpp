#include <bits/stdc++.h>
using namespace std;
string s[51];
stack<string> st;
// 정렬하면 접두어가 가장 앞에 있게된다. 접두어들을 빼면서 스택에 넣고
// 최종적으로 스택의 사이즈가 정답이 된다.
// 증명은 어려우나 왠지 될 것 같았음.
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> s[i];
	sort(s, s + n);
	st.push(s[0]);
	for (int i = 1; i < n; i++) {
		string s2 = st.top();
		if (s2.size() <= s[i].size()) {
			bool flag = true;
			for (int j = 0; j < s2.size(); j++) {
				if (s2[j] != s[i][j]) {
					flag = false;
					break;
				}
			}
			if(flag)st.pop();
		}
		st.push(s[i]);
	}
	cout << st.size() << '\n';
}