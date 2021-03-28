#include <bits/stdc++.h>
using namespace std;
map<long long, bool> d[9];
//다이나믹 프로그래밍
//정답보고품
//아직도 풀이의 원리가 정확히 이해안감
int solution(int N, int number) {
	for (int i = 1, cnt = 0; i <= 8; i++) {
		cnt = cnt * 10 + N;
		d[i][cnt] = true;
	}
	for (int i = 2; i <= 8; i++) {
		for (int j = 1; j < i; j++) {
			for (auto o : d[j]) {
				for (auto p : d[i - j]) {
					d[i][o.first + p.first] = true;
					d[i][o.first - p.first] = true;
					d[i][o.first * p.first] = true;
					if (p.first) {
						d[i][o.first / p.first] = true;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 8; i++) {
		if (d[i][number])return i;
	}
	return -1;
}