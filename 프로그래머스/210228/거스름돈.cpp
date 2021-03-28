#include <bits/stdc++.h>
using namespace std;
//다이나믹 프로그래밍
//d[i] = 현재 가지고 있는 동전들로 만들 수 있는 i 원의 경우의 수
long long d[100001];
const long long MOD = 1000000007;
int solution(int n, vector<int> money) {
    for (int i = 1; i <= n; i++)d[i] = 0;
    d[0] = 1;
    for (auto k : money) {
        for (int i = k; i <= n; i++) {
            d[i] += d[i - k];
            d[i] %= MOD;
        }
    }
    return d[n];
}