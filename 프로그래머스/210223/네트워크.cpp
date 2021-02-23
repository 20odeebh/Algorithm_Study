#include <bits/stdc++.h>
using namespace std;
//연결 요소의 갯수 찾기
bool c[200];
vector<int> v[200];
void dfs(int x) {
    c[x] = true;
    for (auto k : v[x]) {
        if (c[k] == false)dfs(k);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++)c[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)continue;
            if (computers[i][j])v[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (c[i] == false) {
            dfs(i);
            answer++;
        }
    }
    return answer;
}