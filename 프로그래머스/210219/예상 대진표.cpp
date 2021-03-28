#include <bits/stdc++.h>
using namespace std;
//큐에 참가자와 라운드를 넣고 
//2개씩 뺀 후 1개씩 푸쉬
queue<pair<int,int>> q;
int solution(int n, int a, int b)
{
    int answer = 3;
    if (a > b)swap(a, b);
    for (int i = 1; i <= n; i++)q.push({ i,1 });
    while (!q.empty()) {
        int x = q.front().first, x2=q.front().second;
        q.pop();
        int y = q.front().first, y2=q.front().second;
        q.pop();
        if (x == a && y == b)return y2;
        if (x == a) {
            q.push({ x,x2 + 1 });
            continue;
        }
        if (x == b) {
            q.push({ x,x2 + 1 });
            continue;
        }
        if (y == a) {
            q.push({ y,y2 + 1 });
            continue;
        }
        if (y == b) {
            q.push({ y,y2 + 1 });
            continue;
        }
        q.push({ x,x2 + 1 });
    }
    return answer;
}
