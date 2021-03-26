#include <bits/stdc++.h>

using namespace std;

int n,ret=-987654321;
string s;
vector<int> num;
vector<char> op;

int oper(int c, int a, int b) {
	if (c == '+')return a + b;
	if (c == '-')return a - b;
	if (c == '*')return a * b;
}
void go(int here, int _num) {
	if (here == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}
	go(here + 1, oper(op[here], _num, num[here + 1]));
	if (here + 2 <= num.size() - 1) {
		int temp = oper(op[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(op[here],_num, temp));
	}
	return;
}
int main() {
	cin>>n >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2)op.push_back(s[i]);
		else num.push_back(s[i] - '0');
	}
	go(0, num[0]);
	cout << ret;
}
