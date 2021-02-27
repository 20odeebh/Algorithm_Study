#include <bits/stdc++.h>
using namespace std;
//처음엔 다익스트라로 풀었으나 시간초과나서 정답참조
//플로이드 와샬
int d[201][201];
const int MAX = 100000 * 201;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    int size = fares.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)d[i][j] = 0;
            else d[i][j] = MAX;
        }
    }
    for (int i = 0; i < size; i++) {
        d[fares[i][0]][fares[i][1]] = fares[i][2];
        d[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
    }
    return answer;
}