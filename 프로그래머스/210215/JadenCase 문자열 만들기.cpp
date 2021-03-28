#include <bits/stdc++.h>
using namespace std;
//구현
string solution(string s) {
	//앞이 스페이스면 flag 는 true
	bool flag = true;
	for (int i = 0; i < s.size(); i++) {
		if (flag) {
			if (s[i] >= 'a' && s[i] <= 'z')s[i] -= 32;
		}
		else {
			if (s[i] >= 'A' && s[i] <= 'Z')s[i] += 32;
		}
		if (s[i] == ' ')flag = true;
		else flag = false;
	}
	return s;
}
int main() {
	cout << (int)'a' << ' ' << (int)'A' << '\n';
}