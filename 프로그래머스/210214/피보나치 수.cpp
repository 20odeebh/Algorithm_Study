#include <bits/stdc++.h>
using namespace std;
int d[100001];
const int mod = 1234567;
//다이나믹 프로그래밍
int solution(int n) {
	d[0] = 0; d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= mod;
	}
	return d[n];
}