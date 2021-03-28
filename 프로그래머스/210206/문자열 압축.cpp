#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//분할단위를 1~size/2 까지 나누어 브루트포스
int solution(string s) {
	int answer = 0;
	answer = s.size();
	int s2 = s.size() / 2;
	//l= 분할단위
	for (int l = 1; l <= s2; l++) {
		string last = "";
		int sum = 0, templ = 0;
		int i2 = (s.size() / l) * l;
		for (int i = 0; i < i2; i += l) {
			int j2 = i + l;
			string cur = "";
			//cur에 현재 문자열 추가
			//substr(i,l) 식으로 더 깔끔히 수정 가능
			for (int j = i; j < j2; j++) {
				cur += s[j];
			}
			if (cur == last) {
				templ++;
				if (j2 == i2) {
					if (templ > 1) {
						int templ2 = templ, cnt = 0;
						while (templ2) {
							templ2 /= 10;
							cnt++;
						}
						sum += (last.size() + cnt);
					}
				}
			}
			else {
				sum += last.size();
				if (templ > 1) {
					int templ2 = templ, cnt = 0;
					while (templ2) {
						templ2 /= 10;
						cnt++;
					}
					sum += cnt;
				}
				last = cur;
				templ = 1;
				if (j2 == i2) {
					sum += last.size();
				}
			}
		}
		sum += (s.size() - i2);
		answer = min(answer, sum);
	}
	return answer;
}
int main() {
	cout << solution("xxxxxxxxxxyyy");
}