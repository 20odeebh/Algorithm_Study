#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//현재 위치가 1이고 다음 위치가 0인수를 찾아서
//숫자를 바꿔주고 나머지 1개수만큼 앞으로 떙겨주는 방식
int solution(int n) {
	int answer = 0;
	string s = "";
	while (n) {
		if (n % 2)s += '1';
		else s += '0';
		n /= 2;
	}
	int size = s.size();
	//cout << s << '\n';
	s += '0';
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] == '1')cnt++;
		if (s[i + 1] == '0') {
			if (cnt) {
				cnt--;
				s[i + 1] = '1';
				for (int j = 0; j < cnt; j++)s[j] = '1';
				for (int j = cnt; j <= i; j++)s[j] = '0';
				break;
			}
		}
	}
	//cout << s << '\n';
	int start = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')answer += start;
		start *= 2;
	}
	return answer;
}
//int main() {
//	solution(6);
//}