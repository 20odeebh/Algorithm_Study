#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int N, result = INT_MIN;
string str;
int calc(char op, int num1, int num2)
{
	switch (op) {
	case '+':
		return num1 + num2;
	case '*':
		return num1 * num2;
	case '-':
		return num1 - num2;
	}
}
void dfs(int idx, int sum)
{
	if (idx > N - 1) {
		result = max(result, sum);
		return;
	}
	char op = idx == 0 ? '+' : str[idx - 1];
	if (idx + 2 < N) {
		int temp = calc(str[idx + 1], str[idx] - '0', str[idx + 2] - '0');
		dfs(idx + 4, calc(op, sum, temp));
	}
	dfs(idx + 2, calc(op, sum, str[idx] - '0'));
}
int main()
{
	cin >> N >> str;
	dfs(0, 0);
	printf("%d\n", result);
	return 0;
}