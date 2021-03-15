#include <bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans = INT64_MIN;
//우선순위가 다른줄 알고 엄청 고민했던 문제
//앞에꺼 더하고 넘기는지, 뒤에꺼 더한후 앞에꺼 더하고 넘기는지
//완전탐색

long long op(char oper,long long a,long long b) {
	if (oper == '+')return a += b;
	if (oper == '-')return a -= b;
	if (oper == '*')return a *= b;
}
void go(int idx,long long sum) {
	if (idx >= s.size()) {
		ans = max(ans, sum);
		return;
	}
	go(idx+2,op(s[idx], sum, s[idx + 1] - '0'));
	if (idx + 2 < s.size()) {
		long long temp=op(s[idx + 2], s[idx + 1] - '0', s[idx + 3] - '0');
		go(idx + 4, op(s[idx], sum, temp));
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> s;
	if (n == 1) {
		cout << s[0] - '0';
		return 0;
	}
	go(1, s[0] - '0');
	cout << ans << '\n';
}