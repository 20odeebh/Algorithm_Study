#include <bits/stdc++.h>
using namespace std;
string a, b;
stack<char> st;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	char blast = b[b.size() - 1];
	for (int i = 0; i < a.size(); i++) {
		st.push(a[i]);
		//스택에 있는 글자가 B의 마지막 글자면
		if (a[i] == blast) {
			if (st.size() >= b.size()) {
				string temp = "";
				for (int j = 0; j < b.size(); j++) {
					temp += st.top();
					st.pop();
				}
				bool flag = true;
				//하나라도 틀리면 다시 스택에 푸쉬
				for (int j = 0; j < b.size(); j++) {
					if (b[j] != temp[b.size() - j - 1]) {
						flag = false;
						break;
					}
				}
				if (flag == false) {
					for (int j = b.size() - 1; j >= 0; j--) {
						st.push(temp[j]);
					}
				}
			}
		}
	}
	string ans = "";
	if (st.empty()) {
		cout << "FRULA";
		return 0;
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}