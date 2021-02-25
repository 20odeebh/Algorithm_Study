#include <bits/stdc++.h>
using namespace std;
//왼쪽 위쪽에서 경우의수를 합해서 계산
//puddles의 조건이 순서가 반대로 주어진것이 함정
//출력 값 확인할때 시간초과 뜰 수 있음
long long d[101][101];
bool water[101][101];
const long long MOD = 1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {
    int size = puddles.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = 0;
            water[i][j] = false;
        }
    }
    for (int i = 0; i < size; i++) {
        water[puddles[i][1] - 1][puddles[i][0] - 1] = true;
    }
    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (water[i][j])continue;
            if (i > 0) {
                if (water[i - 1][j] == false) {
                    d[i][j] += d[i - 1][j];
                    d[i][j] %= MOD;
                }
            }
            if (j > 0) {
                if (water[i][j - 1] == false) {
                    d[i][j] += d[i][j - 1];
                    d[i][j] %= MOD;
                }
            }
        }
    }
    return d[n - 1][m - 1];
}