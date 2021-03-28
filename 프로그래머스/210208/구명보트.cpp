#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int c[241];
//가장 큰 몸무게 인원 태우고, 남은 보트 제한 중 제일 큰 몸무게 한명을 찾아서 태우는 방법
int solution(vector<int> people, int limit) {
	int answer = 0;
	for (auto k : people) {
		c[k]++;
	}
	for (int i = limit; i > 39; i--) {
		int dif = limit - i;
		dif = min(dif, i);
		while (c[i]) {
			c[i]--;
			for (int j = dif; j > 39; j--) {
				if (c[j]) {
					c[j]--;
					break;
				}
			}
			answer++;
		}
	}
	return answer;
}
