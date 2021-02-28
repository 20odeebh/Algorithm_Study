#include <bits/stdc++.h>

using namespace std;
//다이나믹 프로그래밍
//d[i] = i번째 칸까지 올 수 있는 경우의 수
const long long MOD = 1234567;
long long d[2001];
long long solution(int n) {
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
        d[i] %= MOD;
    }
    return d[n];
}