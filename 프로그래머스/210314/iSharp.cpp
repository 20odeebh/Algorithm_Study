#include <bits/stdc++.h>
using namespace std;
//끝에서부터 변수형 출력
//시작에서부터 변수 출력
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string first, s;
	cin >> first;
	while (cin >> s) {
		cout << first;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '*' || s[i] == '&')cout << s[i];
			if (s[i] == ']')cout << '[';
			if (s[i] == '[')cout << ']';
		}
		cout << ' ';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z')cout << s[i];
			if (s[i] >= 'A' && s[i] <= 'Z')cout << s[i];
		}
		cout << ";\n";
	}
}