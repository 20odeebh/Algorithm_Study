#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>

using namespace std;
// 33분 28분 못품 ㅋㅋ
int n;
// 괄호 추가
int res = INT_MIN;
string str;

int cal(int a, char op, int b) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a + (-1 * b);
	else
		return a*b;
}

void dfs(int idx, int val) {
	if (idx >= n) {
		res = max(res, val);
		return;
	}
	char op;
	if (idx == 0)
		op = '+';
	else
		op = str[idx - 1];
	// 괄호로 묶기
	if (idx + 2 < n) {
		int tmp = cal(str[idx] - '0', str[idx + 1], str[idx + 2] - '0');
		dfs(idx + 4, cal(val, op, tmp));
	}
	// 괄호 안묶기
	dfs(idx + 2, cal(val, op, str[idx]-'0'));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> str;
	// 어떻게 계산해야하나
	dfs(0, 0);
	cout << res;
}