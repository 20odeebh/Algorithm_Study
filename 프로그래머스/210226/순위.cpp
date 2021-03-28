#include <bits/stdc++.h>
using namespace std;
//자신보다 실력이 낮은 선수만 저장하는 그래프, 
//자신보다 실력이 높은 선수만 저장하는 그래프를 만들어서
//양쪽 dfs한 후 더한값이 n이면 순위를 매길 수 있다
//이때 본인이 2번 체크되니 더한값에 -1을 해줘야함.
vector<int> left1[101], right1[101];
bool check[101];
int lcnt = 0, rcnt = 0;
void leftdfs(int x) {
    lcnt++;
    check[x] = true;
    for (auto k : left1[x]) {
        if (check[k] == false) {
            leftdfs(k);
        }
    }
}
void rightdfs(int x) {
    rcnt++;
    check[x] = true;
    for (auto k : right1[x]) {
        if (check[k] == false) {
            rightdfs(k);
        }
    }
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int size = results.size();
    for (int i = 0; i < size; i++) {
        right1[results[i][0]].push_back(results[i][1]);
        left1[results[i][1]].push_back(results[i][0]);
    }
    for (int i = 1; i <= n; i++) {
        lcnt = 0; rcnt = 0;
        for (int j = 1; j <= n; j++)check[j] = false;
        leftdfs(i);
        for (int j = 1; j <= n; j++)check[j] = false;
        rightdfs(i);
        if (lcnt + rcnt - 1 == n) {
            answer++;
        }
    }
    return answer;
}