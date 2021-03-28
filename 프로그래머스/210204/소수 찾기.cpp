#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 완전 탐색
bool c[10000000] = { 0, }, p[10000000] = { 0, };
int solution(string numbers) {
	int answer = 0;
	p[0] = true;
	p[1] = true;
	for (long long i = 2; i < 10000000; i++) {
		if (p[i] == false) {
			for (long long j = i * i; j < 10000000; j += i) {
				p[j] = true;
			}
		}
	}
	sort(numbers.begin(), numbers.end());
	do {
		string temp = "";
		for (int i = 0; i < numbers.size(); i++) {
			temp += numbers[i];
			int num = stoi(temp);
			if (c[num])continue;
			c[num] = true;
			if (p[num] == false)answer++;
		}
	} while (next_permutation(numbers.begin(), numbers.end()));
	return answer;
}