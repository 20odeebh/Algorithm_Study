#include <bits/stdc++.h>
using namespace std;
//프림 알고리즘
struct A {
    int y, c;
    bool operator< (const A& p)const {
        return c > p.c;
    }

};
vector<A> v[101];
priority_queue<A> pq;
bool check[101];
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 1; i <= n; i++)check[i] = false;
    int size = costs.size();
    for (int i = 0; i < size; i++) {
        v[costs[i][0]].push_back({ costs[i][1],costs[i][2] });
        v[costs[i][1]].push_back({ costs[i][0],costs[i][2] });
    }
    pq.push({ 1,0 });
    while (!pq.empty()) {
        int x = pq.top().y, c = pq.top().c;
        pq.pop();
        if (check[x])continue;
        check[x] = true;
        answer += c;
        for (auto k : v[x]) {
            pq.push(k);
        }
    }
    return answer;
}