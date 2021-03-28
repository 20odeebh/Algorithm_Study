#include <iostream>
#include <string>
using namespace std;
/*
접근
1. 결과 문자열을 저장, 폭발 문자열의 마지막 문자와 비교
2. 일치하는 문자가 있다면, 폭발 문자열의 길이만큼 비교 후 길이가 같다면 pop_back
2.1 결과 문자열의 인덱스 조정
*/
int main()
{
	string str, bomb;
	cin >> str >> bomb;
	int idx = 0, bomb_len = bomb.length();
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		result.push_back(str[i]);
		idx++;
		if (result[idx - 1] == bomb[bomb_len - 1]) {
			int cnt = 1;
			for (int j = 1; j < bomb_len; j++) {
				if (result[idx - j - 1] != bomb[bomb_len - j - 1]) {
					break;
				}
				cnt++;
			}
			if (cnt == bomb_len) {
				for (int k = 0; k < bomb_len; k++)
					result.pop_back();
				idx -= bomb_len;
			}
		}
	}
	if (result.length() != 0)
		printf("%s\n", result.c_str());
	else
		printf("FRULA\n");
	return 0;
}