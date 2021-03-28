#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
//슬라이딩 윈도우
int solution(int n) {
	int answer = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
		q.push(i);
		if (sum == n) {
			answer++;
			continue;
		}
		if (sum > n) {
			while (sum > n) {
				sum -= q.front();
				q.pop();
			}
			if (sum == n)answer++;
		}
	}
	return answer;
}