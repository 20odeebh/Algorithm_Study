// 보물상자 비밀번호

#include <stdio.h>
#include <deque>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int test_case, n, k;
int res;
deque<char> dq;
set<string, greater<string>> s;

bool desc(int f1, int f2) {
	return f1 > f2;
}

int calculate(char input) {
	if (49 <= input && input <= 57)
		return (input - 48);
	else if (65 <= input && input <= 70)
		return (input - 55);
	else
		return 0;
}

void lotate() {
	for (int i = 0; i < n / 4; i++) {
		string str;
		for (int j = 0; j < n; j++) {
			str += dq[j];
			if (j % (n / 4) == ((n / 4) - 1)) {
				s.insert(str);
				str.clear();
			}
		}
		dq.push_front(dq.back());
		dq.pop_back();
	}

	int idx = 0;
	set<string>::iterator iter = s.begin();
	for (iter; iter != s.end(); iter++) {
		idx++;
		if (idx == k)
			break;
	}
	string str = *iter;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		res += (pow(16, (len - 1) - i) * calculate(str[i]));
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	char input;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		dq.clear();
		s.clear();
		scanf(" %d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf(" %1c", &input);
			dq.push_back(input);
		}
		lotate();
		printf("#%d %d\n", tc, res);
	}
	return 0;
}