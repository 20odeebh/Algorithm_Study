#include <bits/stdc++.h>
using namespace std;
long long d[60001];
const long long MOD = 1000000007;
//다이나믹 프로그래밍
//n칸의 수는 n-1과 n-2번째 칸의 경우의수를 더한 값 
int solution(int n) {
	d[1] = 1; d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= MOD;
	}
	return d[n];
}