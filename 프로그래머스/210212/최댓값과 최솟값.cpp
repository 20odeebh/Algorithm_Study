#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//단순 구현
string solution(string s) {
	string answer = "";
	long long MIN = INT64_MAX, MAX = INT64_MIN;
	bool minus_flag = false;
	int start = 0;

	while (start < s.size()) {
		long long num = 0;
		if (s[start] == '-') {
			minus_flag = true;
		}
		else {
			num += (s[start] - '0');
			minus_flag = false;
		}
		start++;
		while (start < s.size()) {
			if (s[start] == ' ') {
				start++;
				break;
			}
			num *= 10;
			num += (s[start] - '0');
			start++;
		}
		if (minus_flag)num = -num;
		MIN = min(MIN, num);
		MAX = max(MAX, num);
	}
	answer += to_string(MIN);
	answer += ' ';
	answer += to_string(MAX);
	return answer;
}